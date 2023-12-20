#pragma once
#include <string>

class ZNAK {
    private:
        std::string firstname, lastname;
        int birthDay, birthMonth, birthYear, zodiacSign;
    public:
        ZNAK();
        ZNAK(std::string firstname, std::string lastname, int birthDay, int birthMonth, int birthYear, int zodiacSign);
        ~ZNAK();

        std::string getFirstName() const;
        std::string getLastName () const;
        std::string getZodiacSign() const;
        int getBirthDay() const;
        int getBirthMonth() const;
        int getBirthYear() const;
        std::string getBirthDate() const;

        friend std::istream& operator>>(std::istream& in, ZNAK& ob);
        friend std::ostream& operator<<(std::ostream& out, ZNAK& ob);
};
