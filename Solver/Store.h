#include <string>
#include <vector>
#include <memory>
#include "Product.h"
#include "Author.h"

namespace MusicStore {

    /**
     * @brief ����� ������� (�������� �����, �� �� ������� ��� ����� �� ������, �.�. �� ����������� ����� ������� ������� ��� ������������� ��������)
     * ������ ����� ������������ ����� ����������� �������, �� ����� �������� ��������, ������ � ��������, ��� ��������� � ���
     */
    class Store {
    private:
        std::string name;
        std::string address;
        std::vector<std::shared_ptr<Product>> products;

    public:
        Store(std::string name, std::string address);
        void addProduct(std::shared_ptr<Product> product);

        /**
        * @brief ����� ��� �������� ��������
        * @return ���������� �������� ��������
        */
        std::string getName() const;

        /**
        * @brief ����� ��� �������
        * @return ���������� ������
        */
        std::string getAddress() const;

        /**
        * @brief ����� ��� ���������
        * @return ���������� ������ ���������� �� ��������, ��� �������� � ��������
        */
        const std::vector<std::shared_ptr<Product>>& getProducts() const;
        /**
         * @brief �������, ������������ �������� � ��������� ���������
         * @param tittle - �������� ���������, ������� ��� ����� ����������
         * @return �������� � ��������� ��������� (������ ���������� �� ���)
         */
        std::vector<std::shared_ptr<Product>> getProductsByTitle(const std::string& title) const;

        /**
         * @brief �������, ������������ �������� � ��������� ����� ������� �� ����������
         * @param year - ��� ������� ����������
         * @return �������� � ��������� ����� ������� �����
         */
        std::vector<std::shared_ptr<Product>> getProductsByYear(int year) const;

        /**
         * @brief �������, ������������ �������� � ��������� ����� �� ����������
         * @param genre - ���� ����������
         * @return �������� � ��������� ������
         */
        std::vector<std::shared_ptr<Product>> getProductsByGenre(const std::string& genre) const;

        /**
         * @brief �������, ������������ �������� � ��������� ������� �� ����������
         * @param artist - ����� 
         * @return �������� � ��������� ������� 
         */
        std::vector<std::shared_ptr<Product>> getProductsByArtist(const std::string& artist) const;
    };
}