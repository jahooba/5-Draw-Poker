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



 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` (aka Sprint Backlog) column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

>
>

<img width="785" alt="casino-navigation-diagram" src="https://github.com/cs100/final-project-atham011-jpena079-rrao011-skaka008/assets/146978995/074fbace-9069-49d7-94f3-c14a2e4ac9ad">


### Descrtiption
> This nagivation diagram shows the different ways in which the user can navigate the program. They can beging by either logging in to an existing account or creating a new log in, which will then promt them to log in using their new account. After that the user will be taken to a home page where they can either check their profile, begin playing poker, or logout. By checking out their profile they can view both thier stats and account balance. If the user chooses to instead play poker, they will be given the option to resume an existing game, or start a new game. While playing, the user will be prompted to take different poker actions until either the game is finished or they choose to puase and exit the game. Both scenerios will take the user back to the home page from which they have the option to logout.
>

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).

<img src="images/diagrams/Casino Game Class Diagram.drawio.png" alt="Class Diagram">

### Poker
This is a typical game of Texas hold'em poker. The class contains a map for win conditions, a vector of all participating players, a Deck to distribute cards out of, and a Hand to keep track of cards drawn. It can also score Hands according to its own algorithm, to see who wins the game.
<br>
<br>

### Hand
The hand stores a vector of Cards, and has functionality relating to adding to / dealing from the hand. In addition, the hand can sort itself automatically.

#### Deck
A Deck is a special type of hand, that has all the same functionality, but also automatically generates a 52-card deck, and can distribute a random card from that deck. 

#### Cards
Cards are a struct that hold both a suit, and a value. Both of which can hold values similar to a standard 52-card deck, respectively.
<br>
<br>

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
* Hold
* Bet
* Fold

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
