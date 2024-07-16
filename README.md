# Program prezentujący działanie układu pamięci

## Opis

Ten dokument opisuje działanie programu demonstrującego układ pamięci (memory layout) w kontekście hierarchii klas w języku C++. Program zawiera klasy bazowe (`Object`), klasy pochodne (`Rectangle`, `Image`) oraz klasę wielokrotnie dziedziczoną (`Button`). Komentarze w kodzie ilustrują rozkład pamięci dla każdej klasy.

## Struktura Klas

### Klasa `Object`

Podstawowa klasa zawierająca jedną metodę `equals` oraz jedno pole danych `m_data`.

```cpp
class Object {
public:
    void equals()
    {
        std::cout << "Object enter" << "\n";
        std::cout << "Object exit" << "\n";
    };

    int m_data = 0;
};
```

### Klasa `Rectangle`

Dziedziczy po klasie `Object` i dodaje jedno pole danych `m_dataRect`.

```cpp
class Rectangle : public Object
{
public:
    int m_dataRect = 0;
};
```

### Klasa `Image`

Dziedziczy po klasie `Object` i dodaje jedno pole danych `m_dataImage`.

```cpp
class Image : public Object {
public:
    int m_dataImage = 0;
};
```

### Klasa `Button`

Dziedziczy wielokrotnie po klasach `Rectangle` i `Image`, dodając pole danych `m_dataButton`.

```cpp
class Button : public Rectangle, public Image {
public:
    int m_dataButton = 0;
};
```

## Układ Pamięci

### Klasa `Object`

Układ pamięci dla klasy `Object` (16 bajtów):

- Wskaźnik do tablicy wirtualnych funkcji (vtable) - 8 bajtów
- Pole `m_data` - 4 bajty
- Wyrównanie (padding) - 4 bajty

### Klasa `Rectangle`

Układ pamięci dla klasy `Rectangle` (24 bajty):

- Wskaźnik do tablicy wirtualnych funkcji (vtable) - 8 bajtów
- Pole `m_data` - 4 bajty
- Wyrównanie (padding) - 4 bajty
- Pole `m_dataRect` - 4 bajty
- Wyrównanie (padding) - 4 bajty

### Klasa `Image`

Układ pamięci dla klasy `Image` (24 bajty):

- Wskaźnik do tablicy wirtualnych funkcji (vtable) - 8 bajtów
- Pole `m_data` - 4 bajty
- Wyrównanie (padding) - 4 bajty
- Pole `m_dataImage` - 4 bajty
- Wyrównanie (padding) - 4 bajty

### Klasa `Button`

Układ pamięci dla klasy `Button` (56 bajtów):

- Wskaźnik do tablicy wirtualnych funkcji (vtable) z klasy `Image` - 8 bajtów
- Pole `m_data` z klasy `Image` - 4 bajty
- Wyrównanie (padding) - 4 bajty
- Pole `m_dataRectangle` - 4 bajty
- Wyrównanie (padding) - 4 bajty
- Wskaźnik do tablicy wirtualnych funkcji (vtable) z klasy `Rectangle` - 8 bajtów
- Pole `m_data` z klasy `Rectangle` - 4 bajty
- Wyrównanie (padding) - 4 bajty
- Pole `m_dataImage` - 4 bajty
- Wyrównanie (padding) - 4 bajty
- Pole `m_dataButton` - 4 bajty
- Wyrównanie (padding) - 4 bajty

### Ilustracja Hierarchii Dziedziczenia

```
          Object
          /    \
    Rectangle  Image
          \    /
          Button
```

## Przykład Użycia

### Funkcja `main`

W funkcji `main` tworzony jest obiekt klasy `Button`, co powoduje alokację pamięci zgodnie z układem przedstawionym powyżej.

```cpp
int main() {
    Button b;
    return 0;
}
```

### Konstruktor Przenoszący i Operator Przenoszenia

Konstruktory i operatory przenoszące dla klasy `String` zostały skomentowane. Przy ich użyciu można by zaobserwować konstrukcję i destrukcję obiektów z użyciem mechanizmu przenoszenia.

```cpp
class String {
public:
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
        std::cout << "Constructor: " << data << "\n";
    }

    ~String() {
        delete[] data;
        std::cout << "Destructor\n";
    }

    String(String&& other) noexcept {
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor: " << data << "\n";
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assignment: " << data << "\n";
        }
        return *this;
    }

private:
    char* data;
    size_t size;
};
```

## Podsumowanie

Program demonstruje układ pamięci w kontekście hierarchii dziedziczenia w języku C++. Poprzez komentarze w kodzie wyjaśniono, jak są rozmieszczone pola danych oraz wskaźniki do tablic wirtualnych funkcji (vtable).
