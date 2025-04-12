# 🎲 Board Game Lending Tracker — Design Document

## 📋 Program Specification

This program is a lightweight system designed to help manage a board game lending library at a local board game café. It will track a collection of board games, the number of available copies, and which customer has borrowed which games. The system allows users to view all available games, check out a game to a customer, and return games when they are brought back.

The key entities include games, customers, and lending records. The system provides functionality for checking availability, handling game checkouts and returns, and generating reports of who has borrowed what.

---

## 🧠 Nouns and Verbs

### Nouns (Entities / Attributes)
- Game
- Customer
- GameLibrary
- LendingRecord
- GameID
- Name
- DueDate
- AvailableCopies
- BorrowedGames

### Verbs (Behaviors / Actions)
- Add a game
- Remove a game
- List all games
- Check out a game
- Return a game
- Track borrowed games
- View borrowed records

---

## 🧱 Class Declarations

### Game Class

```cpp
class Game {
public:
    Game(int id, const std::string& title, int copies);

    int getId() const;
    std::string getTitle() const;
    int getAvailableCopies() const;
    void checkout();
    void returnGame();

private:
    int gameId;
    std::string title;
    int availableCopies;
};

### # Customer Class
```cpp

class Customer {
public:
    Customer(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
    void borrowGame(int gameId);
    void returnGame(int gameId);
    const std::vector<int>& getBorrowedGames() const;

private:
    int customerId;
    std::string name;
    std::vector<int> borrowedGameIds;
};

### GameLibrary Class
```cpp

class GameLibrary {
public:
    void addGame(const Game& game);
    void addCustomer(const Customer& customer);
    void listGames() const;
    bool checkoutGame(int gameId, int customerId);
    bool returnGame(int gameId, int customerId);
    void viewBorrowedGames(int customerId) const;

private:
    std::unordered_map<int, Game> games;
    std::unordered_map<int, Customer> customers;
};

### 🏗️ Class Diagram
```mermaid

classDiagram
    class Game {
        - int gameId
        - std::string title
        - int availableCopies
        + Game(int, string, int)
        + int getId()
        + string getTitle()
        + int getAvailableCopies()
        + void checkout()
        + void returnGame()
    }

    class Customer {
        - int customerId
        - std::string name
        - vector<int> borrowedGameIds
        + Customer(int, string)
        + int getId()
        + string getName()
        + void borrowGame(int)
        + void returnGame(int)
        + vector<int>& getBorrowedGames()
    }

    class GameLibrary {
        - unordered_map<int, Game> games
        - unordered_map<int, Customer> customers
        + void addGame(Game)
        + void addCustomer(Customer)
        + void listGames()
        + bool checkoutGame(int, int)
        + bool returnGame(int, int)
        + void viewBorrowedGames(int)
    }

    GameLibrary --> Game : manages
    GameLibrary --> Customer : manages
    Customer --> Game : borrows >
