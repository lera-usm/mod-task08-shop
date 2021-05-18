# МИПиС

## Task 08. Моделирование СМО: "магазин"

Срок выполнения работы: **до 1 июня**

![GitHub pull requests](https://img.shields.io/github/issues-pr/UNN-IASR/mod-task08-shop)
![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed/UNN-IASR/mod-task08-shop)

![Relative date](https://img.shields.io/date/1622494800)

### Задание

> Написать программу, которая моделирует обслуживание покупателей в супермаркете. Идея задачи состоит в том, что покупатели подходят к кассам в случайные моменты времени и с тележками, содержащими случайное количество продуктов (std::vector). 

В модели магазина существует несколько касс (потоков обслуживания) и поток покупателей с продуктовыми тележками. Покупатели появляются в случайные моменты времени и направляются к свободным кассам. Если свободной кассы нет, то они встают в общую очередь. Длина очереди конечна и после заполнения покупатели уходят, ничего не купив.

Входные параметры модели:

- количество касс (каналов обслуживания)
- интенсивность потока покупателей (заявки на обслуживание)
- скорость обработки товара на кассе
- среднее количество товаров в тележке покупателя
- максимальная длина очереди 

Каждая касса обслуживает покупателя в отдельном потоке, что дает возможность моделировать обслуживание сразу нескольких покупателей в один момент времени. Время обслуживания покупателя зависит от количества товаров, находящихся в его тележке (случайный параметр).

Программа должна накапливать статистику:

- обслуженные/необслуженные покупатели
- средняя длина очереди
- среднее время нахождение покупателя в очереди + на кассе
- среднее время работы кассы
- среднее время простоя кассы

На основании накопленной статистики подсчитать:

- вероятность отказа
- относительную пропускную способность магазина
- абсолютную пропускную способность

Сравнить рассчитанные на основе накопленных данных значения с теоретическими

Теоретический материал по данной работе представлен в лекции №6 курса МИПиС.


## Состав проекта

- **include/task.h" - заголовочный файл для задачи
- **src/task.cpp" - исходный файл для задачи
- **src/main.cpp" - главный файл для задачи


## Список участников/веток

см. репозиторий `mod-branches`

## Алгоритм выполнения работы

Для выполнения работы необходимо:

1. Выполнить *fork* репозитария в свой аккаунт.
1. Выполнить клонирование репозитария из своего аккаунта к себе на локальную машину (`git clone`).
1. Создать ветку **git** с индивидуальным номером (`git branch имя_ветки`).
1. Сделать ветку активной (`git checkout имя`).
1. Необходимо разместить как исходные файлы с решениями задач, поместив **cpp** файлы в **src**, а заголовочные - в **include**.
1. Добавить файлы в хранилище (`git add`).
1. Выполнить фиксацию изменений (`git commit -m "комментарий"`).
1. Отправить содержимое ветки в свой удаленный репозитарий (`git push origin имя_ветки`).
1. Создать пул-запрос в репозитарий группы и ждать результата от **GitHub Actions**.


