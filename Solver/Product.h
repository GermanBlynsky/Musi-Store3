#pragma once
#include <string>
#include <memory>
#include "Composition.h"

namespace MusicStore {

    /**
     * @brief ����� �������
     * ������ ����� ������������ ����� ����� � ����������� ��������, �������� �����, ������� ���� ����� (�� ����� � �������), ����, ������ �������, �������� ����������
     */
    class Product {
    private:
        std::shared_ptr<Composition> composition;
        double price;
        std::string address;
        std::string carrier;

    public:
        Product(std::shared_ptr<Composition> composition, double price, std::string address, std::string carrier);

        /**
         * @brief ����� ��� ��������� �� ����������
         * @return ���������� ��������� �� ����������
         */
        std::shared_ptr<Composition> getComposition() const;

        /**
         * @brief ����� ��� ����
         * @return ���������� ����
         */
        double getPrice() const;

        /**
         * @brief ����� ��� �������
         * @return ���������� ������
         */
        std::string getAddress() const;

        /**
         * @brief ����� ��� ��������
         * @return ���������� ���������� �������� �������� �����
         */
        std::string getCarrier() const;
    };
}