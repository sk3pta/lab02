## Laboratory work II


### Part I

1. **Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).**
2. **Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.**
	```bash
	mkdir lab02 && cd lab02
	git init
	git remote add origin git@github.com:nnnnnmmmmm092/lab02.git
	git branch -m main
	git pull origin main
	```
3. **Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.**
```bash
vim hello_world.cpp
```
``` cpp
#include <iostream>
using namespace std;
int main() 
{
cout << "Hello,World! " << endl;
}
```

4. **Добавьте этот файл в локальную копию репозитория.**
``` bash
git add hello_world.cpp
```
5. **Закоммитьте изменения с *осмысленным* сообщением.**
```bash 
git commit -m "Hello,World! ver.01"
```
6. **Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.**
```bash
vim hello_world.cpp
```
```cpp 
#include <iostream>
using namespace std;
int main() 
{
	char uname[50] = "";
	cin >> uname;
cout << "Hello,World! from  " <<uname << endl;
}
```
7. **Закоммитьте новую версию программы.** 
 ``` bash
 git add hello_world.cpp
 git commit -m "hello_world ver2"
``` 
8. **Почему не надо добавлять файл повторно `git add`?**
``` -----```
9. **Запуште изменения в удалёный репозиторий.**
```bash
git push origin main
```
10. **Проверьте, что история коммитов доступна в удалёный репозитории.**
![[commits.png]]


### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. **В локальной копии репозитория создайте локальную ветку `patch1`.**
```bash
git checkout -b patch1
```
2. **Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.**
```bash
vim hello_world.cpp
```
```cpp
#include <iostream>

int main() 
{
	char uname[50] = "";
	std::cin >> uname;
	std::cout << "Hello,World! from  " <<uname << std::endl;
}
```
3. ** _commit_, _push_ локальную ветку в удалённый репозиторий.**
```bash 
git add hello_world.cpp
git commit -m "Better codestyle"
git push origin patch1
```
4. **Проверьте, что ветка `patch1` доступна в удалёный репозитории.**
![[patch1.png]]
5. **Создайте pull-request `patch1 -> master`.**
6. **В локальной копии в ветке `patch1` добавьте в исходный код комментарии.**
```bash
vim hello_world.cpp
```
```cpp
#include <iostream>

int main() 
{	//var uname contains username
	char uname[50] = "";

	// getting uname from input stream
	std::cin >> uname;

	//printing out
	std::cout << "Hello,World! from  " <<uname << std::endl;
}
```
7. **commit**, **push**.
```bash
git add hello_world.cpp
git commit -m "Comments"
git push origin patch1
```
8. **Проверьте, что новые изменения есть в созданном на **шаге 5_pull-request**
![[pr2.png]]
9. **удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.**

10. Локально выполните **pull**.
```bash
git switch main
git pull origin main
```
11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.
```bash
git log

```
12. Удалите локальную ветку `patch1`.
```bash
git branch -D patch1
Deleted branch patch1 (was e4357d0).

```

### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. **Создайте новую локальную ветку `patch2`.**
```bash
git checkout -b patch2
```
2. **Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.**
```bash
clang-format  -style=Mozilla hello_world.cpp 
```
3. **commit**, **push**, создайте pull-request `patch2 -> master`.
```bash
git add hello_world.cpp
git commit -m "Mozilla codestyle"
git push origin patch2
```
4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
5. Убедитесь, что в pull-request появились *конфликтны*.
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
```bash
git pull origin main
git rebase main

```
7. Сделайте *force push* в ветку `patch2`
```bash
git push --force origin patch2
```
9. Убедитель, что в pull-request пропали конфликтны.
10. Вмержите pull-request `patch2 -> master`.
