### Requirements

As we ask clarifying questions, we should note down the key requirements for this problem. Putting the key requirements in writing will help us avoid ambiguity and contradictions, as there is nothing worse than realizing you are solving the wrong problem.

Here are the key functional requirements we’ve identified:

 - The parking lot has multiple parking spots, including compact, regular, and oversized spots.
 - The parking lot supports parking for motorcycles, cars, and trucks.
 - Customers can park their vehicles in spots assigned based on vehicle size.
 - Customers receive a parking ticket with vehicle details and entry time at the entry point and pay a fee based on duration, vehicle size, and time of day at the exit point.

Below are the non-functional requirements:

 - The system must scale to support large parking lots with many spots and vehicles.
 - The system must reliably track spot assignments and ticket details to ensure accurate operations.
 
 With these requirements set, we now identify the core objects.

 ### Class Diagram

 ![Parking Lot Class Diagram](https://drive.google.com/file/d/1l3KR37RP-N0y8q5ih5rOFAoRgK3Ss1s0/ "Parking Lot")