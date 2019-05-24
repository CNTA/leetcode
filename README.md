# Hướng dẫn submit file bài giải Leetcode lên repo

### Tổ chức folder
Mỗi người sẽ có một folder ở repo root. Các folder của từng người chứa các bài giải mà người đó đã làm, đặt tên theo số ID và tên bài chính xác trên Leetcode để dễ theo dõi.

Ví dụ
```($repo_root)/giang/3. Longest Substring Without Repeating Characters/```

Các file `.gitignore` đặt vào trong folder riêng của từng người. Vì mỗi người làm một (hoặc nhiều) ngôn ngữ khác nhau nên anh em chủ động tự chuẩn bị file .gitignore cho từng ngôn ngữ mà mình chọn. Nếu không biết chuẩn bị file .gitignore như thế nào có thể xem qua repo này, khá đầy đủ: https://github.com/github/gitignore

### Commit message
- Mỗi commit tương ứng với một bài, push thẳng lên nhánh master.
- Commit message cần để format như sau: `[Tên][Ngôn ngữ] Bài`, ví dụ `[Giang][C++] 3. Longest Substring Without Repeating Characters`.
- Khi pull bài của anh em khác về nên dùng rebase để giữ commit log được tuyến tính, tránh các commit merge làm rối.

Cuối cùng là chúc anh em học hỏi được nhiều thứ với Leetcode.