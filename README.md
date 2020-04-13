# task_for_1C  Задача А001
Idea and solution of task for 1C

## Алгоритм:

На входный словах строим бор. В каждой вершине бора будем хранить массив вершин с индексированием по буквам, куда можем перейти из текущей вершине по этой букве, также будем хранить вершину-предка откуда мы пришли, будем хранить приоритет вершины - это максимальный приоритет доступного слова, которые имеют такой префикс, флаг терминальная она или нет, и приоритет текущей вершины. Приоритет из условия задачи - это повторяющихся слов.

# Построение бора:

Шаг 1. Создадим дерево из одной вершины (в нашем случае корня).

Шаг 2. Добавление элементов в дерево.
Добавляем шаблоны P_i один за другим. Следуем из корня по рёбрам, отмеченным буквами из P_i, пока возможно.
Если P_i заканчивается в вершине v, сохраняем идентификатор P_i (например, i) в v и отмечаем вершину v как терминальную.
Если ребра, отмеченного очередной буквой P_i нет, то создаем новое ребро и вершину для символа строки P_i.
Конец.

Шаг 3. Релаксация.
Будем поддерживать в каждой вершине пару (максимальный приоритет, буква) доступного слова. 
Если мы попави в терминальную вершину и она уже была терминальной --- увеличиваем счетчик приоритета и производим релаксацию. Идем от текущей вершины в корень и пересчитываем максимальным приоритет.

Построение завершено.

# Прогнозирование слова по префиксу

На вход получем слово и начинаем идти по бору. Идем по каждой букве слова. Когда слово закончится продолжаем идти по бору по максимальному приоритету до первого терминала. Таким образом мы попадем в слово которое встречалось в тексте наибольшее количество раз. Если на пути два одинаковых приоритета, идем по обоим путям и выбираем то где первым достигнем терминала. Сверяем текущий приоритет и максимальный приоритет данной вершины чтоб понять надо ли одти дальше.

