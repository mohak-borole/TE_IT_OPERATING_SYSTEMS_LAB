#!/bin/bash

book=addressbook.csv

while true;
do
	echo -e "1.Create Book \n2.View book \n3.insert record \n4.Search Record \n5.Delete Record \n6.Modify \n7.Exit \nRecord\nENTER YOUR CHOICE"
	read CH
	case $CH in
		"1")
		echo "Creating a Address Book"
		touch $book
		;;
		
		"2")
		echo "Openning address book"
		cat $book
		;;
			 
		"3")
		echo "Inserting a record..."
		read -p "Enter the record in the format 'Last name,First name,Email,Phone number': " record
	 	echo "$record" >> $book
		;;
		
		"4")
		echo -en "You have selected Search record\n"
		read -p "Enter the name to search: " name
		grep "$name" $book
		;;
		
		"5")
		echo "Deleting a record..."
	  	read -p "Enter the last name of the record to delete: " last_name
	  	grep "$last_name" $book || {
			echo "No record found with last name $last_name"
			return 1
	  	}
	  	sed -i "/$last_name,/d" $book
		;;
		
		"6")
		echo "Modifying a record..."
	  	read -p "Enter the last name of the record to modify: " last_name
	  	grep "$last_name" $book || {
   		echo "No record found with last name $last_name"
	    		return 1
	  	}
	  	lineNumber=$(grep -n "$last_name" $book | cut -c1)
	  	read -p "Enter the new record in the format 'Last name,First name,Email,Phone number': " record
	  	sed -i "${lineNumber}s/.*/$record/" $book
		;;
		
		"7")
		exit;;
		
		*)
		echo -n "Invalid"
		;;
	esac
done
