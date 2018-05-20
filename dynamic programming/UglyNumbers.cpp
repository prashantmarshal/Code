1 Declare an array for ugly numbers:  ugly[n]
2 Initialize first ugly no:  ugly[0] = 1
3 Initialize three array index variables i2, i3, i5 to point to 
   1st element of the ugly array: 
        i2 = i3 = i5 =0; 
4 Initialize 3 choices for the next ugly no:
         next_mulitple_of_2 = ugly[i2]*2;
         next_mulitple_of_3 = ugly[i3]*3
         next_mulitple_of_5 = ugly[i5]*5;
5 Now go in a loop to fill all ugly numbers till 150:
for (i = 1; i < 150; i++ ) 
{
    next_ugly_no  = Min(next_mulitple_of_2,
                        next_mulitple_of_3,
                        next_mulitple_of_5); 

    ugly[i] =  next_ugly_no       

    if (next_ugly_no  == next_mulitple_of_2) 
    {             
        i2 = i2 + 1;        
        next_mulitple_of_2 = ugly[i2]*2;
    } 
    if (next_ugly_no  == next_mulitple_of_3) 
    {             
        i3 = i3 + 1;        
        next_mulitple_of_3 = ugly[i3]*3;
     }            
     if (next_ugly_no  == next_mulitple_of_5)
     {    
        i5 = i5 + 1;        
        next_mulitple_of_5 = ugly[i5]*5;
     } 
     
}
6.return next_ugly_no
