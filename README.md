# Практична робота №3
# Лiшенко О.Д.
## Завдання 1


Досліджено максимальний ліміт відкритих файлів за допомогою команди ulimit у Docker-контейнері

### без root:

![image](https://github.com/user-attachments/assets/03b08d60-8a5e-4942-b1c9-4a301980d4aa)

### з root:

![image](https://github.com/user-attachments/assets/b601b926-a026-4d79-87c1-976663291b18)


## Завдання 2


 Встановлено та протестовано утиліту `perf` в Docker-контейнері для досягнення ліміту процесу

![image](https://github.com/user-attachments/assets/a4332fc3-1025-4d97-a628-6c4b72cda394)




## Завдання 3


Написано програму для імітації кидка кубика 


У програмі використовується команда `ulimit -f 15`, яка встановлює обмеження на максимальний розмір файлу

![image](https://github.com/user-attachments/assets/30cc3bff-d0fa-4ea3-bb03-e500bb99d930)




## Завдання 4


Програма для лотереї з обмеженням на час ЦП та обробкою перевищення ліміту

Використовуємо команду `prlimit` для встановлення ліміту на час процесора `(--cpu=1:2)`

![image](https://github.com/user-attachments/assets/f68a7ba0-e4e2-4433-962c-d28011b2c919)



## Завдання 5


Копіювання файлів з перевіркою аргументів та обробкою обмежень на розмір файлів

Встановлюємо ліміт за допомогою setrlimit. 

У Dockerfile компілюється програма, копіюється файл і встановлюється ліміт на розмір файлу перед виконанням копіювання.

![image](https://github.com/user-attachments/assets/b8723b31-fdb1-4551-ac68-44933ae9b0ab)



## Завдання 6

Встановлено ліміт для розміру стеку в 8192 байт за допомогою команди `prlimit --stack=8192`


Реалізовано програму для демонстрації обмеження на максимальний розмір стеку за допомогою рекурсії


![image](https://github.com/user-attachments/assets/09e230f2-16d1-41bb-a956-5837726047bf)



## Завдання 7
### Варіант 11. 

Досліджено вплив `ulimit -s` на роботу рекурсивних алгоритмів в програмі


Обмеження розміру стеку до 1024 байт призвело до сегментаційної помилки

```
$ ulimit -s 1024 && ./7
Segmentation fault (core dumped)
```

При збільшеному ліміті розміру стеку до 8192 байт програма змогла працювати і виконати рекурсивні виклики до глибини 785
```
$ ulimit -s 8192 && ./7
Recursion depth: 1
Recursion depth: 2
Recursion depth: 3
…
Recursion depth: 784
Recursion depth: 785
RecursiSegmentation fault (core dumped)
```

При відключеному ліміті стеку `(unlimited)` програма змогла виконати рекурсивні виклики до глибини понад 1 мільйон
``` 
$ ulimit -s unlimited && ./7
Recursion depth: 1
Recursion depth: 2
Recursion depth: 3
…
Recursion depth: 1610262
Recursion depth: 1610263
R
```

