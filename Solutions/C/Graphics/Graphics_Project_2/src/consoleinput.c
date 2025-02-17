# include <stdio.h>

struct ClimateControl {
    float temperature;  
    float humidity;     
    int fanStatus;
    int luminosity;     
};

// Function to display current settings
void display(struct ClimateControl cc) {
    printf("Temperature: %.1f degree celcius\n", cc.temperature);
    printf("Humidity: %.1f%%\n", cc.humidity);
    printf("Luminosity: %.1f flux\n", cc.luminosity);
    printf("Fan Status: %s\n", cc.fanStatus ? "On" : "Off");
}

void accept(struct ClimateControl *cc) {   
    printf("Enter temperature (degree celcius): ");
    scanf("%f", &cc->temperature);
    printf("Enter humidity (%%): ");
    scanf("%f", &cc->humidity);
    printf("Enter luminosity (%%): ");
    scanf("%f", &cc->luminosity);
    printf("Enter fan status (0 for off, 1 for on): ");
    scanf("%d", &cc->fanStatus);
}

int main()
{
    printf("\n Welcome to Tambade mala Greenhouse Smart System\n");
    struct ClimateControl greenhouseClimate = {22.5, 45.0,5000, 1};
    display(greenhouseClimate);
   
    int choice=1;

    do {
        printf("\n Tambade mala Smart Greenhouse Autionation Climate Control Menu:\n");
        printf("1. Set Climate Control Settings\n");
        printf("2. Display Current Settings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                accept(&greenhouseClimate);
                break;
            case 2:
                display(greenhouseClimate);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}
// g++ -o output  consoleinput.c 