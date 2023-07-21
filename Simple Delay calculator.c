#include <stdio.h>

float transmissionDelay(float R, float L){
    return (L/R); //transmissionDelay = L/R [L - Size of packet and P - Bandwidth aka transmission rate]
}

float propagationDelay(float D, float S){
    return (D/S); //propagationDelay = D/S [D - distance of the medium to travel and Speed of the medium]
}

float totalDelay(float td, float pd){
    return (td+pd); //totalDelay = transmissionDelay + propagationDelay 
                    //[Sum of all delays and queueing delay and processing delay considered zero]
}

float endToEndDelay(float N, float L,float R){
    return (N*(L/R));
}

float main(){
    float L,R,D,S,N,td,pd,tt,endtoend;
    printf("Welcome Simple Delay Calculator - Computer Network\n");
    printf("To Calculate Delays give\n Size of packet, Transmission Rate, Distance of medium, Medium speed and No. of link as input\n");
    scanf("%f %f %f %f %f",&L,&R,&D,&S,&N);
    td = transmissionDelay(R,L);
    pd = propagationDelay(D,S);
    tt = totalDelay(td,pd);
    endtoend = endToEndDelay(N,L,R);
    printf("\nThe Transmission Delay = %f \nThe Propagation Delay = %f \nThe Total Delay = %f \nThe End to End Delay = %f",td,pd,tt,endtoend);
}
