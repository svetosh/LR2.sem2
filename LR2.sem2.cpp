#include <iostream>
#include <string>

using namespace std;

class Family
{
protected:
    string surname;
    uint16_t member_count;
    uint64_t total_income;

public:
    Family(string s_name, uint16_t m_count, uint64_t t_income);
    long double average_income() const;
    void print() const;
    ~Family();
};

class Region
{
protected:
    string r_name;
    uint64_t payoff_size;
    uint64_t aver_income_threshold;

public:
    Region(string name, uint64_t p_size, uint64_t ai_threshold);
    void print() const;
    ~Region();
};

class RegionFamily
    : public Family
    , public Region
{
public:
    RegionFamily(string s_name,
        uint16_t m_count,
        uint64_t t_income,
        string name,
        uint64_t p_size,
        uint64_t ai_threshold);
    long double average_income() const;
    void print() const;
    ~RegionFamily();
};




Family::Family(string s_name, uint16_t m_count, uint64_t t_income)
{
    surname = s_name;
    member_count = m_count;
    total_income = t_income;
}

long double Family::average_income() const
{
    return (total_income / static_cast<float>(member_count));
}

void Family::print() const
{
    cout << "Семейная фамилия: " << surname << endl;
    cout << "Количество членов семьи: " << member_count << endl;
    cout << "Общий доход семьи: " << total_income << endl;
}

Family::~Family()
{
    cout << "Деструктор. семья." << endl;
}

Region::Region(string name, uint64_t p_size, uint64_t ai_threshold)
{
    r_name = name;
    payoff_size = p_size;
    aver_income_threshold = ai_threshold;
}

void
Region::print() const
{
    cout << "Название региона: " << r_name << endl;
    cout << "Размер выплаты по региону: " << payoff_size << endl;
    cout << "Порог среднего дохода по региону: " << aver_income_threshold << endl;
}

Region::~Region()
{
    cout << "Деструктор. регион." << endl;
}

RegionFamily::RegionFamily(std::string s_name,
    uint16_t m_count,
    uint64_t t_income,
    string name,
    uint64_t p_size,
    uint64_t ai_threshold) : Family(s_name, m_count, t_income), Region(name, p_size, ai_threshold)
{
}

long double
RegionFamily::average_income() const
{
    if (Family::average_income() < aver_income_threshold)
    {
        return ((total_income + payoff_size) /
            static_cast<float>(member_count));
    }
    else
    {
        return Family::average_income();
    }
}

void
RegionFamily::print() const
{
    cout << "РегионСемейный объект:" << endl;
    Family::print();
    Region::print();
}

RegionFamily::~RegionFamily()
{
    cout << "Деструктор. РегионСемья" << endl;
}

int
main()
{
    setlocale(LC_ALL, "ru");
    uint16_t number_of_participants = 10;
    uint64_t total_income0 = 12345;
    uint64_t total_income1 = 123;
    std::string name0 = "SN0";
    std::string name1 = "SN1";

    uint64_t payoff_size = 103;
    uint64_t aver_income_threshold = 100;
    string r_name = "RN";

    cout << endl;

    Family f(name0, number_of_participants, total_income0);
    cout << "Семейный образец объекта" << endl;
    f.print();
    cout << "Средний заработок: " << f.average_income() << endl;

    cout << endl;

    Region r(r_name, payoff_size, aver_income_threshold);
    cout << "Объект образца региона" << endl;
    r.print();

    RegionFamily rf0
        (name0,
        number_of_participants,  
        total_income0, 
        r_name,        
        payoff_size,   
        aver_income_threshold);
    RegionFamily rf1
        (name1,
        number_of_participants,
        total_income1,
        r_name,
        payoff_size,
        aver_income_threshold);

    cout << endl;

    cout << "Пример объекта RegionFamily #0" << endl;
    rf0.print();
    cout << "Средний заработок: " << rf0.average_income() << endl;

    cout << endl;

    cout << "Пример объекта RegionFamily #1" << endl;
    rf1.print();
    cout << "Средний заработок: " << rf1.average_income() << endl;
}
