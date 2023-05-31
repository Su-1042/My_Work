#!/bin/bash
                    
        
       
        print_tree() {
        local directory="$1"
        local lines="$2"

            for file in "$directory"/*; do
                local vertical="|"
                local horizontal="--"
        
                local name="$(basename "$file")"
                    if [ -d "$file" ]; then
                    echo "${lines}${vertical}${horizontal}$name"
                    print_tree "$file" "${lines}${vertical}  "
                    else
                    echo "${lines}${vertical}${horizontal}$name"
                    fi
            done
        }

        root="."

            if [ $# -ne 0 ]; then
            root="$1"
            fi

        echo "$root"
        print_tree "$root" ""





        if [[ $3 -eq "-A" ]] 
        then
        ls -a
        
        fi



