#ifndef SECTIONDATA_H
#define SECTIONDATA_H


class SectionData
{
public:
    SectionData();
    SectionData(float);
private:

    float a_;  //Коэф. торможения
    float a2_; //Коэф. закрутки
    float fi_; //Угол потока (рад)
    float dM_dr;  //Момент (Н)
    float dT_dr;  //Осевая сила (Н/м)

};

#endif // SECTIONDATA_H
