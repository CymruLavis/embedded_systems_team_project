#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;


class SQLConnection {
private:
    const string server = "tcp://127.0.0.1:3306";
    const string username = "root";
    const string password = "1260";
    const string dbName = "sys";
    const string menuTable = "menu";
    const string configTable = "system_config";
public:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    SQLConnection() {
        activateDB();
        connectToDB();
    }
    void activateDB() {
        // run scripts or another file to turn initialize the database on the pi
    }
    void connectToDB() {
        try
        {
            driver = sql::mysql::get_driver_instance();
            con = driver->connect(server, username, password);
            con->setSchema(dbName);

        }
        catch (sql::SQLException e)
        {
            cout << "Could not connect to server. Error message: " << e.what() << endl;
            system("pause");
            exit(1);
        }
    }
    string fillMenu() {
        string query = "SELECT * from sys.menu";
        executeQuery(query);
    }
    string getItemDescription(string drink_name) {
        string query = "Select description from sys.menu where drink_name = '" + drink_name + "';";
        executeQuery(query);
    }
    string getAllIngredients() {
        string query =
            "SELECT ingredient1 AS ingredient FROM menu"
            "UNION"
            "SELECT ingredient2 AS ingredient FROM menu"
            "UNION"
            "SELECT ingredient3 AS ingredient FROM menu"
            "UNION"
            "SELECT ingredient4 AS ingredient FROM menu"
            "UNION"
            "SELECT ingredient5 AS ingredient FROM menu"
            "UNION"
            "SELECT ingredient6 AS ingredient FROM menu;";

        executeQuery(query);

    }
    string getReceipe(string drink_name) {
        string query = "Select * from sys.menu where drink_name = '"+drink_name+"';";
        executeQuery(query);
    }

    string getFillLevels() {

    }
    
    void executeQuery(string query) {
        stmt = con->createStatement();
        res = stmt->executeQuery(query);
        system("pause");

        delete stmt;
        delete con;
        delete res;

    }


    void makeDrink() {
        // query the positions of the ingredients
        // 
    }
};

