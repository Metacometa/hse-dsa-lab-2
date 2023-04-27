# Лабораторная работа по алгоритмам и структурам данных #2
# Логин в яндекс.контесте: kibabin@edu.hse.ru

## Задача  
  Даны прямоугольники на плоскости с углами в целочисленных координатах **([1..109],[1..109])**.  
  Требуется как можно быстрее выдавать ответ на вопрос **«Скольким прямоугольникам принадлежит точка (x,y)?»**  
  И подготовка данных должна занимать мало времени.  
UPD: только нижние границы включены => **(x1<= x) && (x<x2) && (y1<=y) && (y<y2)**

## Пример  
Прямоугольники: **{(2,2),(6,8)}, {(5,4),(9,10)}, {(4,0),(11,6)}, {(8,2),(12,12)}**  
Точка-ответ: 
**(2,2)** -> **1**  
**(12,12)** -> **1**  
**(10,4)** -> **2**  
**(5,5)** -> **3**  
**(2,10)** -> **0**  

## Цели лабораторной работы  
  Реализовать три разных решения задачи  
Выяснить при каком объеме начальных данных и точек какой алгоритм эффективнее.  
### Алгоритм перебора
  Без подготовки. При поиске – просто перебор всех прямоугольников  
Подготовка **O(1)**, поиск **O(N)**
### Алгоритм на карте  
  Сжатие координат и построение карты.  
Подготовка **O(N3)**, поиск **O(logN)**  
### Алгоритм на дереве  
  Сжатие координат и построение персистентного дерева отрезков   
Подготовка O(NlogN), поиск O(logN)  

## Рекомендации  
  Для тестового набора прямоугольников, рекомендуется использовать набор вложенных друг-в-друга 
с координатами с шагом больше **1**, например **{(10*i, 10*i), (10*(2N-i), 10*(2N-i))}**.  
Для тестового набора точек, рекомендуется использовать неслучайный набор распределенных 
более-менее равномерно по ненулевому пересечению прямоугольников, например хэш функции от **i** с разным базисом для **x** и **y**.   
**(p*i)^31%(20*N)**, p-большое простое, разное для **x** и **y**

## Выводы

  На графике **"Preprocessing"** отображена подготовка данных.  
Для алгоритма перебором значения нулевые, потому что подготовка данных в алгоритме не используется.  
Заметно, что алгоритм на персистентном дереве шустрее подготавливает данные, да
и в целом длительность подготовки данных увеличивалась медленнее, чем у алгоритма на карте.
Эта разница довольно естественно следует из сложностей подготовок алгоритмов.
Сложность подготовки алгоритма на карте - **O(N^3)** против сложности подготовки алгоритма на дереве - **O(NlogN)**

  На графике **"Queries"** мы видим время запросов.   
Довольно естественно, что на маленьких данных перебор шустрее, он происходит без особо больших контант.  
В то время, как для карты нужно бин поиском пройтись по итератору(итераторы в C++ добавляют чуть-чуть констант в сложность), 
чтобы найти подходящую позицию. Для дерева же, кроме того же самого бинпоиска и итерирования, нужно ещё рекурсивно пройтись по дереву, что тоже добавляет константу.  

  Но на больших данных перебор уже невалиден, в то время как карта и дерево идут вровень. Но карта всё равно несколько шустрее, 
вероятно потому, что хотя в обоих алгоритмах нужно бинарно найти подходящий индекс, 
далее в алгоритме на дереве нам нужно спускаться по дереву за ответом, в то время как в алгоритме на карте просто взять из 
вектора векторов значение за **O(1)**. Хотя скорость на запросах у карты и дерева примерно равна, забывать о том, 
что подготовка данных на карте **ГОРАЗДО** медленее, чем на дереве, не стоит.