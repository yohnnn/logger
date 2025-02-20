# Logger Project

Журнал записи с разными уровнями важности на C++.


## 📌 Особенности

- Поддержка разных уровней важности
- Возможность менять уровень по умолчанию
- Запись в файл

---

## 🔧 Установка и сборка

### 1. Клонирование репозитория

```bash
git clone https://github.com/your_username/logger.git
cd logger
```

### 2. Сборка проекта

```bash
make
```

### 3. Запуск

```bash
./test "файл.txt" "уровень по умолчанию"
```

---

### Пример работы

#### Входные данные:

```bash
./test test_log.txt 1
```

#### Диалог с программой:

```
Выберите:
 1 - записать сообщение
 2 - сменить уровень важности сообщения по умолчанию
 3 - для выхода
1
Введите сообщение для лога: beda
Введите уровень важности (0 - ERROR, 1 - WARNING, 2 - INFO, ENTER - по умолчанию): 0

Выберите:
 1 - записать сообщение
 2 - сменить уровень важности сообщения по умолчанию
 3 - для выхода
1
Введите сообщение для лога: warn
Введите уровень важности (0 - ERROR, 1 - WARNING, 2 - INFO, ENTER - по умолчанию): 1

Выберите:
 1 - записать сообщение
 2 - сменить уровень важности сообщения по умолчанию
 3 - для выхода
1
Введите сообщение для лога: info
Введите уровень важности (0 - ERROR, 1 - WARNING, 2 - INFO, ENTER - по умолчанию): 2

Выберите:
 1 - записать сообщение
 2 - сменить уровень важности сообщения по умолчанию
 3 - для выхода
2
Введите новый уровень важности по умолчанию: 2

Выберите:
 1 - записать сообщение
 2 - сменить уровень важности сообщения по умолчанию
 3 - для выхода
1
Введите сообщение для лога: info
Введите уровень важности (0 - ERROR, 1 - WARNING, 2 - INFO, ENTER - по умолчанию):

Выберите:
 1 - записать сообщение
 2 - сменить уровень важности сообщения по умолчанию
 3 - для выхода
3
Завершение программы...
```

(Сообщение с уровнем INFO не отобразится, если установлен уровень WARNING или ERROR)


### Итоговый файл с записями
```

2025-02-20 13:08:31 [ERROR] jopa
2025-02-20 13:08:41 [WARNING] warn
2025-02-20 13:09:05 [INFO] lil pip

```


