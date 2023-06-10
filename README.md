# Catan
The fxxking game Prof. Chi asked us to implement

# Just Changed
- 加入 -Wall 編譯選項，抓出所有風險
- 去除 -std=c17 的編譯選項，使用預設的 gnu17
- 在 Makefile 中新增 clean 標籤，可清除編出來的程式 (a.out)
- 將函式宣告和實作分開，並將全域變數 map 移至 map.c ，請用 extern 存取
- 將 print_map 函式改成 macro
- 新增 player.h