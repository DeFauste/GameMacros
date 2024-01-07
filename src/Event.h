#ifndef GAMEMACROS_EVENT_H
#define GAMEMACROS_EVENT_H
enum TypeEvent {
  key = 1,
  times = 2,
};
/*базовый класс родительский класс для кнопок и таймеров*/
class Event {
 private:
  int _typeEvent = 0;

 public:

  Event() = default;
  explicit Event(TypeEvent type) : _typeEvent(type) {};
  int getType() const;
};
/*класс кнопки, наследуется от event и расширяется*/
class ButtonEvent : public Event {
 private:
  int _keyCode;
 public:
  /*получаем в конструктор только код кнопки, в конструктор родительского класса передаем тип event*/
  explicit ButtonEvent(int keyCode) : _keyCode(keyCode), Event(key) {};
  int getKey() const;
};
class TimerEvent: public Event {
 private:
  unsigned int _sleepTime = 1000;
 public:
  explicit TimerEvent(unsigned int sleepTime): _sleepTime(sleepTime*1000), Event(times){};
  unsigned int getSleepTime();
};
#endif //GAMEMACROS_EVENT_H
