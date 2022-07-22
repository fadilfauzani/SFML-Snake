#ifndef __EVENTMANAGER__H__
#define __EVENTMANAGER__H__
#include <unordered_map>
#include <functional>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


enum class EventType{
    KeyDown = sf::Event::KeyPressed, //0
    KeyUp = sf::Event::KeyReleased, //1
    MButtonDown = sf::Event::MouseButtonPressed,//2
    MButtonUp = sf::Event::MouseButtonReleased, //3
    MouseWheel = sf::Event::MouseWheelMoved, //4
    WindowResized = sf::Event::Resized, //5
    GainedFocus = sf::Event::GainedFocus, //6
    LostFocus = sf::Event::LostFocus, //7
    MouseEntered = sf::Event::MouseEntered, //8
    MouseLeft = sf::Event::MouseLeft, //9
    Closed = sf::Event::Closed, //10
    TextEntered = sf::Event::TextEntered, //11
    Keyboard = sf::Event::Count + 1,  //12
    Mouse, 
    Joystick
};

struct EventInfo{
    EventInfo(){ m_code = 0; }
    EventInfo(int l_event){ m_code = l_event; }
    union{
    int m_code;
    };
};

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct EventDetails{
    EventDetails(const std::string& l_bindName) : m_name(l_bindName){
        Clear();
    }
    std::string m_name;
    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;

    int m_mouseWheelDelta;
    int m_keyCode; // Single key code.

    void Clear(){
        m_size = sf::Vector2i(0, 0);
        m_textEntered = 0;
        m_mouse = sf::Vector2i(0, 0);
        m_mouseWheelDelta = 0;
        m_keyCode = -1;
    }
};

struct Binding{
    Binding(const std::string& l_name) : m_name(l_name), m_details(l_name), c(0){}

    void BindEvent(EventType l_type, EventInfo l_info = EventInfo()){
        m_events.emplace_back(l_type, l_info);
    }

    Events m_events;
    std::string m_name;
    int c; // Count of events that are "happening".
    EventDetails m_details;
};

using Bindings = std::unordered_map<std::string, Binding*>;

template<class T>
struct Callback{
    std::string m_name;
    T* CallbackInstance; // Pointer to instance.
    void(T::*_callback)();
    void Call(){
        CallbackInstance->*_callback();
    }
};
using Callbacks = std::unordered_map<std::string, std::function<void(EventDetails*)>>;
class EventManager{
public:
    EventManager();
    ~EventManager();
    bool AddBinding(Binding *l_binding);
    bool RemoveBinding(std::string l_name);
    void SetFocus(const bool& l_focus);
    // Needs to be defined in the header!
    template<class T>
    bool AddCallback(const std::string& l_name, void(T::*l_func)(EventDetails*), T* l_instance){
        auto temp = std::bind(l_func,l_instance, std::placeholders::_1);
        return m_callbacks.emplace(l_name, temp).second;
    }
    void RemoveCallback(const std::string& l_name){
        m_callbacks.erase(l_name);
    }
    void HandleEvent(sf::Event& l_event);
    void Update();
    sf::Vector2i GetMousePos(sf::RenderWindow* l_wind = nullptr){
        return (l_wind ? sf::Mouse::getPosition(*l_wind) : sf::Mouse::getPosition());
    }
    private:
    void LoadBindings();
    Bindings m_bindings;
    Callbacks m_callbacks;
    bool m_hasFocus;
};
#endif  //!__EVENTMANAGER__H__