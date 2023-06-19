#ifndef SPRINT_HPP
#define SPRINT_HPP

/**
 * @brief classe que representa uma sprint na metodologia Scrum
 *
 */
class sprint
{
private:
    int id;
    std::string dateStart;
    std::string dateFinal
public:
    sprint(/* args */);
    ~sprint();
    void start(std::string dateStart);
    void final(std::string dateFinal);
};

#endif
