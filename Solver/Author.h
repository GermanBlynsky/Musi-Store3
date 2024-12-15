#pragma once 
#include <string> 
#include <vector> 
#include <memory> 
#include <stdexcept> 

namespace MusicStore {

    class Composition;

    class Author;

    /**
     * @brief ����� �����
     * ������ ����� ������������ ����� ������ ����������, � ���� ���� ��� � ������ ��� ����������
     */
    class Author : public std::enable_shared_from_this<Author> {
    private:
        std::string firstName;
        std::string lastName;
        std::string middleName;
        std::vector<std::weak_ptr<Composition>> compositions;
        Author(std::string firstName, std::string lastName, std::string middleName);
    public:
        static std::shared_ptr<Author> createAuthor(std::string firstName, std::string lastName, std::string middleName);

        /**
         * @brief ����� ��� �����
         * @return ���������� ���
         */
        std::string getFirstName() const;

        /**
         * @brief ����� ��� �������
         * @return ���������� �������
         */
        std::string getLastName() const;

        /**
         * @brief ����� ��� ��������
         * @return ���������� ��������
         */
        std::string getMiddleName() const;

        /**
         * @brief ����� ��� ���������� ������� ������
         * @return ���������� ����
         */
        const std::vector<std::weak_ptr<Composition>>& getCompositions() const;

        /**
         * @brief �������, ������������ ����������, ���������� � ����������� ������ ������� (�� �����)
         * @param startYear - ��������� ������� ��������� ������ ������ ��� ����������
         * @param endYear - �������� ������� ��������� ������ ������ ��� ����������
         * @return ���������� ����������, ���������� � �������� �������� �������
         */
        std::vector<std::weak_ptr<Composition>> getCompositionsByYearRange(int startYear, int endYear) const;
        
        /**
         * @brief ������� ���������� ����������
         * @param composition - ����������, ������� �� ��������� ������
         */
        bool AddComposition(std::shared_ptr<Composition> const& composition);
    };
}