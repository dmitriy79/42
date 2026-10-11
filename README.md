# 1. Сбрасываем старый кэш
rm -rf CMakeCache.txt CMakeFiles/

# 2. Переконфигурируем проект с вашим кастомным OpenSSL
cmake -DOPENSSL_ROOT_DIR=/usr/local/ssl ..

# 3. Запускаем сборку
make -j$(nproc)
