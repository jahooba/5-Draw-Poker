# Casino Game 

## Authors:
[Samyak Kakatur](https://github.com/therealsamyak) | 
[Joshua Pena](https://github.com/jahooba) | 
[Ram Rao](https://github.com/KleeWai) | 
[Arya Thammanna](https://github.com/atham011)

## Project Description


### Why a Casino?
This project involves data collection, data retrieval, and Computer Opponent coding in C++. Normally, this is all done in Python / SQL using databases, instead of the more rudamentry method we are using. However, by limiting ourselves to the basics, we are further demonstrating our knowledge of C++.

Currently, our project features:
* Multiple Casino games (Poker, Craps).

    * All games have a computer opponent.

* Gambling!

    * Users can win / lose money through wagers.
    * Financial and Statistical information is stored to User Profiles so users can restart from where they left off.

* Statistics collected and displayed (both per user, and can be compared globally!):

    * Games played.
    * Money won (or lost) over lifetime of the account
    * Win Rate.
<br>

This will all be done in C++ and its associated, built-in libraries such as iostream, cmath, ctime, and cstdlib.
<br>

This project takes in **Keyboard Input** whenever necessary to interact with all the menus and games. A Keyboard is mandatory to gain the full experience.
<br>

The project can output a variety of different screens **to the terminal**, such as:
* Specific UIs for each of the games.

    * Ex. Your current hand in Poker.

* Menus to go between features of the projects.
* User statistics.


## User Interface Specification

### Navigation Diagram
<img src="images/diagrams/Navigation Diagram.png" alt="Navigation Diagram">


#### Description
This nagivation diagram shows the different ways in which the user can navigate the program. They can beging by either logging in to an existing account or creating a new log in, which will then promt them to log in using their new account. After that the user will be taken to a home page where they can either check their profile, begin playing poker, or logout. By checking out their profile they can view both thier stats and account balance. If the user chooses to instead play poker, they will be given the option to resume an existing game, or start a new game. While playing, the user will be prompted to take different poker actions until either the game is finished or they choose to puase and exit the game. Both scenerios will take the user back to the home page from which they have the option to logout.


### Screen Layout Diagram

#### Opening Screen

<img src="images/diagrams/openingscreen.png" alt="Opening Screen">

This screen is to get the user initiated with their first time playing, and let's them know to create an account or proceed. It also clearly, very simply states the instructions the user needs to follow to create an account or Login, this is a simple screen without any visual clutter so the user can have a good experience.
<br>

#### Create Account Screen

<img src="images/diagrams/createanaccount.png" alt="Create Account Screen">

This is another simple screen where the user is directed to create their username and password, the user is instructed to create a unique and safe password for account safety, and is reassured that we don't save their password anywhere, and at the end the user knows that their creation was successful.
<br>

#### Login Screen

<img src="images/diagrams/loginscreen.png" alt="Login Screen">

This is another simple screen where the user is directed to create their username and password, the user is instructed to create a unique and safe password for account safety, and is reassured that we don't save their password anywhere, and at the end the user knows that their creation was successful.
<br>

#### Main Menu Screen

<img src="images/diagrams/menuscreen.png" alt="Menu Screen">

This is a very simple menu screen where the user can see that they are logged in correctly, and they are also hyper linked to see the latest updates, this is a standard we want to follow from video games. Then the user is simply instructed on how to proceed next, this also has no visual clutter.
<br>

#### Profile Screen

<img src="images/diagrams/profilescreen.png" alt="Profile Screen">

This is a very simple profile screen where the user has the choice to go to two separate screens, and is properly instructed how to do them, we have it like this so we can avoid confusion and visual clutter between balance info and their overall stats.
<br>

#### Statistics Screen

<img src="images/diagrams/statsscreen.png" alt="Statistics Screen">

This is a very simple way the user can get information of their lifetime performance in the game for their own fun and enjoyment, and this adds potential for a leaderboard and adds an aspect of competition.
<br>

#### Balance Screen

<img src="images/diagrams/statsscreen.png" alt="Statistics Screen">

This is a very simple way the user can get information of their lifetime performance in the game for their own fun and enjoyment, and this adds potential for a leaderboard and adds an aspect of competition.
<br>

#### Poker Main Manu Screen

<img src="images/diagrams/pokerstartscreen.png" alt="Poker Start Screen">

In this screen, the user can clearly select an option of their choice, to either start a new game, to resume their old game (if there is one), or to quit to main menu. The screen clearly instructs the user what key to press to get their desired option, and gets rid of visual clutter.
<br>

#### Poker Action Screen

<img src="images/diagrams/pokeractionscreen.png" alt="Poker Action Screen">

On the top of the screen, the user is told that they are in poker action, and they can clearly see their hand  and their current bet in dollars. This way, they already have the most crucial information at their first glance. The rest of the screen serves to let the user know how to pick one of the four actions to do.
<br>



## Class Diagram

<img src="images/diagrams/Casino Game Class Diagram.drawio.png" alt="Class Diagram">

### Poker
This is a typical game of 5-card Draw poker. The class contains a map for win conditions, a vector of all participating players, a Deck to distribute cards out of, and a Hand to keep track of cards drawn. It can also score Hands according to its own algorithm, to see who wins the game.

#### PokerScoreKey\*
This keeps track of all possible Hand types and their scores, so the Poker game can reference them on an as-needed basis. 
<br>

Solid Principles Incorporated: To avoid violation of the **Single-Responsibility Principle**, we have defined PokerScoreKey as its own independent interface. We moved all the private functions that were only related to the scoreKey into this class, as the Poker Game itself didn't need it. The Poker Game is responsible for managing the Poker Game. PokerScoreKey is responsible for scoring Hands according to 5-card Draw Poker standards. This change helped us write better code as it reduced clutter within the Poker game, and allowed for easy testing due to the seperation of responsibilities.
<br>
<br>

### Hand
The hand stores a vector of Cards, and has functionality relating to adding to / dealing from the hand. In addition, the hand can sort itself automatically.

#### Deck\*
A Deck is a special type of hand, that has all the same functionality, but also automatically generates a 52-card deck, and can distribute a random card from that deck. 
<br>

Solid Principles Incorporated: To avoid violation of the **Liskov-Substitution Principle**, we changed the Deck and Hand interfaces to be more similar to each other in functionality. We made sortHand() protected, as the Deck can be sorted similarly to a Hand. In addition, we added a virtual method to obtainCard(Card*) that the Deck class overrides, since the Deck has a larger MAX_SIZE than the hand. This makes it so that any tests that involve the Hand can also involve the Deck, and makes coding easier since we don't have to think twice about member functions only working on one or the other, especially when dealing with the Hand interface.  

#### Cards
Cards are a struct that hold both a suit, and a value. Both of which can hold values similar to a standard 52-card deck, respectively.
<br>
<br>

### Login
Login deals with all the login functionality. User statistics are saved to files, and Login accesses those files and loads the game with the user's data. 

### Player
Player is an abstract class that all players are based off of. All Players have a name, a Hand to hold cards, and a Balance (money to gamble). 

#### Balance
Balance keeps track of a balance, as well as has the ability to modifiy that balance.

#### Statistics
Statistics keeps track of a file (or creates a file if one isn't available), where all the user statistics are stored / updated. 

#### Poker Player
A Poker Player additionally has statistics that are related to their performance in Poker. They also gain the ability to make poker actions.

#### Poker Computer
A special type of Poker Player that has similar functionality, but makes their moves according to an algorithm instead of user-input. 

#### Poker Action
A Poker Action is a struct that has a field for the type of the action as well as the bet amount. 

#### PokerActionTypes
* Check
* Call
* Bet
* Fold
<br>

## Screenshots
<img src="images/diagrams/LoginScreen.png" alt="LoginScreen">
<img src="images/diagrams/ChangePassword.png" alt="ChangePassword">
<img src="images/diagrams/Balance.png" alt="Balance">
<img src="images/diagrams/Statistics.png" alt="Statistics">
<img src="images/diagrams/PokerAction.png" alt="PokerAction">
<br>

## Installation/Usage
**This Application is compiled in 16-bit Windows. This may require you to install an emulator to run this program successfully.**

To install this application
1. Download this repository.
2. Run PokerGame.exe!

## Testing
Our project was tested using the Google C++ Testing Framework. We wrote our own extensive set of unit tests for all parts of our project, and made sure all of them passed before committing any changes.  
 
