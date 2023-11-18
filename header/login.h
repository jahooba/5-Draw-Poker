#include <iostream>
#include <fstream>
#include <string>

class Login {
public:

    Login(const std::string& filename);

    ~Login();

    void registerUser(const std::string& username, const std::string& password);

    bool authenticateUser(const std::string& username, const std::string& password);

private:

    std::string filename;

    bool isLoggedIn;

    void loadUserData();

    void saveUserData();
};

#endif // LOGIN_H