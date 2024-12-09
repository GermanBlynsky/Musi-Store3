#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

namespace MusicStore {

    class Author;

    /**
     * @brief ����� ����������
     * ������ ����� ������������ ����� ����������: ����� ��� ����������� (�� ���������� ������), � �� ���� ��������, ���� � ������
     */
    class Composition {
    private:
        std::string title;
        std::string genre;
        int releaseYear;
        std::vector<std::shared_ptr<Author>> authors;

    public:

        Composition(std::string title, std::string genre, int releaseYear, std::vector<std::shared_ptr<Author>> authors);
        
        /**
         * @brief ����� ��� ��������
         * @return ���������� ��������
         */
        std::string getTitle() const;

        /**
        * @brief ����� ��� �����
        * @return ���������� ����
        */
        std::string getGenre() const;

        /**
        * @brief ����� ��� ���� �������
        * @return ���������� ��� ������� 
        */
        int getReleaseYear() const;

        /**
        * @brief ����� ��� �������
        * @return ���������� ������ ������� ����������
        */
        const std::vector<std::shared_ptr<Author>>& getAuthors() const;
    };
}