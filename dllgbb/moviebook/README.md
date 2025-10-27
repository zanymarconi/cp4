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

```plantuml
@startuml
class MovieBookingSystem {
    - vector<Movie> movies
    - vector<Cinema> cinemas
    - ScreeningManager screeningManager
    + bookTicket()
}
MovieBookingSystem --> ScreeningManager
MovieBookingSystem --> Cinema

class Order {
    - vector<Ticket> tickets
}
Order "1" *-- "many" Ticket: has a

class ScreeningManager {
    - map<string, vector<Screening>> screeningsByMovie
    - map<string, vector<Ticket>> ticketsByScreeningId
    + getScreeningForMovie()
    + getAvailableSeatsForScreening()
}
ScreeningManager --> Screening

class Ticket {
    - Screening screening
    - Seat seat
    - double price
}
Ticket --> Screening

class Cinema {
    - string name
    - map<string, Room> roomsByNumber
}
Cinema "1" *-- "many" Room: have a

class Screening {
    - string screeningId
    - Movie movie
    - Room room
    - long long startMillis
}
Screening --> Movie
Screening --> Room

class Movie {
    - string title
    - int durationInMinutes
}

class Room {
    - string roomNumber
    - Layout layout
}
Room --> Layout

class Layout {
    - vector<vector<Seat>> seatByPosition
    - map<string, Seat> seatByNumber
    + addSeat
    + getSeat // overloaded
}
Layout "1" --> "many" Seat: has

class Seat {
    - string seatNumber
    - PricingStrategy pricing
}
Seat --> PricingStrategy

abstract PricingStrategy {
    + double getPrice()
}
class NormalRate implements PricingStrategy
class PremiumRate implements PricingStrategy
class VIPRate implements PricingStrategy
@enduml