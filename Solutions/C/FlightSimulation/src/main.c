
#include "flight.h"
#include "Queue.h"
#include <string.h>
#include <stdio.h>

int main() {
    struct Queue* queue = createQueue(5);

    struct Flight flight1;
    //Initialize flight details

    strcpy(flight1.destination,"Delhi");
    flight1.flight_id=123;
    
    //Add inside Queue
    enqueue(queue, flight1); // Enqueued at index 0

    struct Flight flight2;
    strcpy(flight2.destination,"Mumbai");
    flight2.flight_id=129;
    enqueue(queue, flight2); // Enqueued at index 1

    struct Flight flight3;
    strcpy(flight3.destination,"Chennai");
    flight3.flight_id=234;
    enqueue(queue, flight3); // Enqueued at index 1

    display(queue);
    
    
    struct Flight theFlightToLand=dequeue(queue);
    printf("Signalled fop landing: %d %s \n", theFlightToLand.flight_id, theFlightToLand.destination);
    theFlightToLand=dequeue(queue);
    printf("Signalled fop landing: %d %s \n", theFlightToLand.flight_id, theFlightToLand.destination);
    ("Signalled fop landing: %d %s \n", theFlightToLand.flight_id, theFlightToLand.destination);
    
    display(queue);
    return 0;
}