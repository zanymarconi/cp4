## Overview
Design a movie booking system.

## Requirements
### Requirements Clarifications
 - Pricing tiear for seats?
   - Yes: normal, permium, VIP
 - Multiple tickets in single order allowed?
   - Yes: total cost is returned for selected seats
 - What happens after booking?
   - Ticket with booked seat, screening, price

### Functional Requirements
 - Movie and Screeening Management
   - Each movie can have multiple screenings
 - Seat Management & Pricing
   - Each cinema can have multiple rooms.
   - Each room have a layout (for flexibility)
 - User Search & Book Flow
   - Get available seats
   - Get movie ticket

## Code Design
### Objects
 - Movie: Title & Duration
 - Layout: is a Dynamic Seat Arrangment
 - Room: has a Layout
 - Cinema: has list of Rooms
 - Screening: Movie, Room and Time Slot
 - Ticket: Screening, Seat & Price
 - Order: Multiple Tickets & Total Price
 - ScreeningManager (Facade): Movie to Screens Map & Screens to Tickets Map
 - MovieBookingSystem (Facade): List of Movies and Cinema. ScreeningManager

 Facade pattern helps with loose coupling. Startegy pattern allows flexibility.

### Class Diagram

![Movie Booking System Class Diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/zanymarconi/cp4/refs/heads/main/dllgbb/moviebook/mbclassdiag.iuml)

#### View PlantUML
 - VSCode Readme.md Preview: Install VSCode extensions - PlantUML (jebbs) & Markdown Plantuml Preview (myml)
 - VSCode .iuml Preview: Mac - Install Java & GraphViz
 - Github Readme.md: Use image URL 
   ```
   ![Movie Booking System Class Diagram](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/zanymarconi/cp4/refs/heads/main/dllgbb/moviebook/mbclassdiag.iuml)
   ```