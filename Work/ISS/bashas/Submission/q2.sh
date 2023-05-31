#!/bin/bash



while getopts :C: options; do
        case $options in
            C) optn=$OPTARG

            if [ $optn == "insert" ]
                then
                while getopts :f:l:n:o: options; do
                    case $options in
                    f) fname=$OPTARG;;
                    l) lname=$OPTARG;; 
                    n) mobile=$OPTARG;;
                    o) office=$OPTARG;;
                    esac
                done

                if grep -q $fname contacts.csv;
                    then
                    echo "Unable to insert contact!"
                    exit 0

                    else
                    echo "$fname,$lname,$mobile,$office" >> contacts.csv
                fi

            fi


            

            if [ $optn == "display" ]

                then
               
                while getopts "ad" options;
                do
                    case $options in
                    a) as=1;;
                    d) de=0;;
                    esac
                done

                    

                    if [[ $as == 1 ]] 
                    then
                    cat contacts.csv | tail -n +2 | sort 
                    
                    elif [[ $de == 0 ]]
                    then
                    cat contacts.csv | tail -n +2 | sort -r
                    
                    else
                    cat contacts.csv |tail -n +2

                    fi    

            fi 




            if [ $optn == "search" ]
                then 
                while getopts :c:v: options; do
                    case $options in
                    c) column2find=$OPTARG;;
                    v) value=$OPTARG;;
                    esac
                done

                if [[ $column2find == "fname" ]]
                then 
                    if cat "contacts.csv" | tail -n +2 | grep -q -e "$value,.*,.*,.*"
                    #searches for the patttern in the given csv file and returns true if the pattern is found and prints i
                    then cat "contacts.csv" | tail -n +2 | grep -e "$value,.*,.*,.*"
                    else echo "No results found!"
                    fi
    
                elif [[ $column2find == "lname" ]]
                then 
                    if cat "contacts.csv" | tail -n +2 | grep -q -e ".*,$value,.*,.*"
                    then cat "contacts.csv" | tail -n +2 | grep -e ".*,$value,.*,.*"
                    else echo "No results found!"
                    fi
                elif [[ $column2find == "mobile" ]]
                then 
                    if cat "contacts.csv" | tail -n +2 | grep -q -e ".*,.*,$value,.*"
                    then cat "contacts.csv" | tail -n +2 | grep -e ".*,.*,$value,.*"
                    else echo "No results found!"
                    fi

                elif [[ $column2find == "office" ]]
                then 
                    if cat "contacts.csv" | tail -n +2 | grep -q -e ".*,.*,.*,$value"
                    then cat "contacts.csv" | tail -n +2 | grep -e ".*,.*,.*,$value"
                    else echo "No results found!"
                    fi

                # if grep -q -w $what2find contacts.csv;
                # #-w will search for the whole word matches
                # #-q means quite mode in grep it gives 1 or true if pattern exist and 0 if pattern doesnt 
                # #it wont allow grep to print anything on its own 
                # echo "$column2find"
                # then 
                # grep -w $what2find contacts.csv
                
                else 
                echo "No Results found!"
                
                fi

            fi




            if [ $optn == "delete" ]
                then 
                while getopts :k: options; do
                    case $options in
                    k) fname=$OPTARG;;
                    esac
                done

                sed -i '/'$fname'/d' contacts.csv 

            fi

    # sed: This command is a stream editor that can be used to modify text.
    # -i: This option tells sed to modify the file in place (i.e., to save changes to the original file).
    # '/pattern/d': This is the pattern to search for. In this case, it will match any line that contains the given pattern. The d command tells sed to delete the line.
    # filename: This is the name of the file to edit.



            if [ $optn == "edit" ]
    
                then 
                fname="zero"
                lname="zero"
                mobile="zero"
                company="zero"

                while getopts :k:f:l:n:o: options; do
                    case $options in
                    k) contact2bedited=$OPTARG;;
                    f) fname=$OPTARG;;
                    l) lname=$OPTARG;;
                    n) mobile=$OPTARG;;
                    o) company=$OPTARG;;
                    esac
                done
                

                
                while IFS="," read -r column1 column2 column3 column4
        do
                if test "$contact2bedited" = "$column1"
                then
                        if test "$fname" != "zero"
                        then
                                sed -i "s/$column1/$fname/" contacts.csv
                        fi

                        if test "$lname" != "zero"
                        then
                                sed -i "s/$column2/$lname/" contacts.csv
                        fi

                        if test "$mobile" != "zero"
                        then
                                sed -i "s/$column3/$mobile/" contacts.csv
                        fi

                        if test "$company" != "zero"
                        then
                                sed -i "s/$column4/$company/" contacts.csv
                        fi

                break
                fi
        done < contacts.csv
                # sed -i "s/^$contact2bedited,.*/$fname,$lname,$mobile,$company/g" contacts.csv

                #function is able to edit when all details are given but doesnt work for partial details given


            fi
            
            


        esac
done



