#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

namespace MusicStore {

    class Composition;

    /**
     * @brief ����� �����
     * ������ ����� ������������ ����� ������ ����������, � ���� ���� ��� � ������ ��� ����������
     */
    class Author {
    private:
        std::string firstName;
        std::string lastName;
        std::string middleName;
        std::vector<std::shared_ptr<Composition>> compositions;

    public:
        Author(std::string firstName, std::string lastName, std::string middleName);

        /**
         * @brief ������� ���������� ����������
         * @param composition - ����������, ������� �� ��������� ������
         */
        void addComposition(std::shared_ptr<Composition> composition);

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
        const std::vector<std::shared_ptr<Composition>>& getCompositions() const;

        /**
         * @brief �������, ������������ ����������, ���������� � ����������� ������ ������� (�� �����)
         * @param startYear - ��������� ������� ��������� ������ ������ ��� ����������
         * @param endYear - �������� ������� ��������� ������ ������ ��� ����������
         * @return ���������� ����������, ���������� � �������� �������� �������
         */
        std::vector<std::shared_ptr<Composition>> getCompositionsByYearRange(int startYear, int endYear) const;
    };
}