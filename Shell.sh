ADD 2 NO.
echo "Enter two numbers"
read num1 num2
sum = 'expr $num1 + $num2'
echo "The sum is = $sum"

EVEN ODD
echo "Enter a Number:"
read n
rem=$(( $n % 2 ))
if [ $rem -eq 0 ]
then
    echo "Number is even"
else
    echo "Number is odd"
fi

Sum Of N NO.
echo "Enter Size(N)"
read N
i=1
sum=0
echo "Enter Numbers"
while [ $i -le $N ]
do
  read num           #get number
  sum=$((sum + num)) #sum+=num
  i=$((i + 1))
done
echo $sum

Factorial
echo "Enter a number"
read num
fact=1
while [ $num -gt 1 ]
do
  fact=$((fact * num))  #fact = fact * num
  num=$((num - 1))      #num = num - 1
done
echo $fact

File Directory

echo " Enter Name "
read f
if test -f $f
then
echo " $f is a file "
if test -d $f
then 
echo " $f is a directory "
fi
fi

