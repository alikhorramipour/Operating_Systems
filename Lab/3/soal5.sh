var1=$1
var2=1
varTmp=0
case $var1 in

	1)
		for var2 in 1 2 3 4 5
    		do 
			until [ $varTmp == $var2 ]
			do
				echo -ne $var2
				varTmp=$(($varTmp + 1))
			done 
		echo
		varTmp=0
		var2=$(($var2 + 1))
    		done
    	;;


	0)
		for var2 in 1 2 3 4 5
    		do 
			until [ $varTmp == $var2 ]
			do
				echo -ne " "
				varTmp=$(($varTmp + 1))	
			done
			echo -ne "*" 
			until [ $varTmp == $var2 ]
			do
				echo -ne " "
				varTmp=$(($varTmp + 1))	
			done
			
    		done



	;;

	2)
		p=6; 
		for((m=1; m<=p; m++)) 
		do
   			for((a=i; a<=p-m; a++)) 
    			do
      				echo -ne " "; 
    			done
    		for((n=1; n<=m; n++)) 
    		do
      			echo -ne "* "; 
    		done
    		
    		echo; 
		done

		for((m=p; m>=1; m--)) 
		do
   			for((a=p-m; a>=i; a--)) 
    			do
      				echo -ne " "; 
    			done
    		for((n=m; n>=1; n--)) 
    		do
      			echo -ne "* "; 
    		done
    		echo; 
		done
	;;


	3)
		echo "|_"
		for var2 in 1 2 3 4
    		do 
			until [ $varTmp == $var2 ]
			do
				echo -ne "| "
				varTmp=$(($varTmp + 1))	
			done 
			echo "|_"
			varTmp=0
			var2=$(($var2 + 1))
    		done
    	;;
 

	*)
		echo "Wrong Entry"
	;;
esac
