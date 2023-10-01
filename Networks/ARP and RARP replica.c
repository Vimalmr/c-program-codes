#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()

int main() {
    char ip[10][20] = {"192.168.0.64", "192.168.0.60", "192.168.0.68", "132.147.3.3"};
    char et[10][20] = {"00_A8_00_40_8E_FS", "00_16_17_31_8e_22", "00_16_17_31_8E_F7", "00_16_17_31_8E_08"};
    
    char ipaddr[20], etaddr[20];
    int i, op;
    int x = 0, y = 0;
    
    while (1) {
        printf("\n\n 1.ARP 2.RARP 3.EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("\n Enter IP address: ");
                scanf("%s", ipaddr);
                
                for (i = 0; i < 10; i++) { // Corrected loop bound
                    if (strcmp(ipaddr, ip[i]) == 0) {
                        printf("MAC address is %s\n", et[i]);
                        x = 1;
                        break; // Exit loop once a match is found
                    }
                }
                if (x == 0) {
                    printf("Invalid IP address\n");
                }
                x = 0;
                break;
            case 2:
                printf("Enter MAC address: ");
                scanf("%s", etaddr);
                
                for (i = 0; i < 10; i++) { // Corrected loop bound
                    if (strcmp(etaddr, et[i]) == 0) {
                        printf("IP address is %s\n", ip[i]);
                        y = 1;
                        break; // Exit loop once a match is found
                    }
                }
                if (y == 0) {
                    printf("Invalid MAC address\n");
                }
                y = 0;
                break;
                
            case 3:
                exit(0); // Exit the program
        }
    }
    
    return 0;
}

