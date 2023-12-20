#pragma once
#include <string>
#include <vector>

class Note {
    private:
        std::string firstname;
        std::string lastname;
        std::string phone;
        std::string description = "нет";
        std::vector<int> createDate = {-1, -1, -1};
        std::vector<int> birthDate = {-1, -1, -1};

        void setCreateDate();
    public:
        Note();
        Note(
            const std::string& firstname,
            const std::string& lastname,
            const std::string& phone,
            const std::string& description = "",
            const std::string& birthDate = ""
        );
        ~Note();

        std::string getFirstname();
        std::string getLastname();
        std::string getPhone();
        std::string getDescription();
        std::string getCreateDate() const;
        std::string getBirthDate() const;

        std::string toString();

        std::vector<int> getCreateDateAsVector();
        std::vector<int> getBirthDateAsVector();

        int getCreateDateDay() const;
        int getCreateDateMonth() const;
        int getCreateDateYear() const;
        int getBirthDateDay() const;
        int getBirthDateMonth() const;
        int getBirthDateYear() const;

        static std::string dateToString(const std::vector<int>& date);
        static std::vector<int> stringToDate(const std::string& date);

        friend std::istream& operator>>(std::istream& in, Note& ob);
        friend std::ostream& operator<<(std::ostream& out, Note& ob);
};
