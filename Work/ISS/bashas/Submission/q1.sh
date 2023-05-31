#!/bash/bin

read -p "Enter Name: " Name
read -p "Enter Age: " months years

if [ $months == '08' ]
    then
    months=8
fi   

if [ $months == '09' ]
    then
    months=9
fi 

declare -i a=2023 b=$years c=a-b-1
declare -i d=$months e=3 f=12 g=f+e-d
declare -i h=$c i=12 j=h*i
declare -i k=$j l=$g m=k+l

echo "Hello $Name, your age is $m months."















