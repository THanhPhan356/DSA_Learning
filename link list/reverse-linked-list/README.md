# Reverse Linked List

**Đề bài:** [NeetCode – Reverse Linked List](https://neetcode.io/problems/reverse-a-linked-list/question?list=neetcode150)

Đảo hướng liên kết của danh sách liên kết đơn và trả về node đầu mới. Cả hai cách dưới đây sử dụng lại các node hiện có.

```text
Trước: 1 → 2 → 3 → null
Sau:   3 → 2 → 1 → null
```

## 1. Iterative — dùng vòng lặp

**Code:** [iterative.cpp](iterative.cpp)

Dùng ba biến con trỏ:

- `prev`: đầu của phần đã đảo, ban đầu là `nullptr`.
- `current`: node đang xử lý, ban đầu là `head`.
- `next`: lưu node kế tiếp trước khi sửa liên kết.

Mỗi vòng thực hiện theo thứ tự:

1. `next = current->next`: giữ đường tới phần chưa xử lý.
2. `current->next = prev`: đảo liên kết của node hiện tại.
3. `prev = current`: cập nhật đầu của phần đã đảo.
4. `current = next`: chuyển sang node kế tiếp.

Ví dụ với `1 → 2 → 3`:

| Sau bước | Phần đã đảo (`prev`) | Phần chưa xử lý (`current`) |
| --- | --- | --- |
| Khởi tạo | `null` | `1 → 2 → 3 → null` |
| Xử lý node 1 | `1 → null` | `2 → 3 → null` |
| Xử lý node 2 | `2 → 1 → null` | `3 → null` |
| Xử lý node 3 | `3 → 2 → 1 → null` | `null` |

Khi `current == nullptr`, trả về `prev`. Phải lưu `next` trước khi đổi `current->next`, nếu không sẽ mất đường tới phần còn lại.

## 2. Recursive — dùng đệ quy

**Code:** [recursive.cpp](recursive.cpp)

1. Nếu danh sách rỗng hoặc chỉ có một node, trả về `head`.
2. Gọi `reverseList(head->next)` để đảo phần phía sau; kết quả là `newHead`.
3. `head->next->next = head`: nối node kế tiếp ngược về node hiện tại.
4. `head->next = nullptr`: bỏ liên kết cũ để tránh tạo chu trình.
5. Trả về `newHead` qua các lời gọi.

Ví dụ khi xử lý node 1: phần `2 → 3` đã được đảo thành `3 → 2 → null`. Con trỏ `head->next` vẫn trỏ tới node 2; gán `head->next->next = head` tạo liên kết `2 → 1`. Sau đó gán `head->next = nullptr` để có `3 → 2 → 1 → null`.

## So sánh

| Cách | Thời gian | Bộ nhớ phụ |
| --- | --- | --- |
| Iterative | O(n) | O(1) |
| Recursive | O(n) | O(n), do stack lời gọi |

Iterative phù hợp khi cần tiết kiệm bộ nhớ hoặc danh sách rất dài. Recursive giúp luyện cách phân rã bài toán nhưng độ sâu lời gọi tăng theo số node.

## Trường hợp cần kiểm tra

| Đầu vào | Kết quả |
| --- | --- |
| `[]` | `[]` |
| `[1]` | `[1]` |
| `[1, 2]` | `[2, 1]` |
| `[1, 2, 3]` | `[3, 2, 1]` |
| `[2, 2, 1]` | `[1, 2, 2]` |

Node cuối sau khi đảo phải trỏ tới `nullptr`. Các node phải được giữ nguyên, chỉ thay đổi liên kết.

## Sử dụng code

Hai file C++ là hai lựa chọn độc lập, mỗi file có lớp `Solution`. Chọn một cách để nộp bài. NeetCode cung cấp sẵn `ListNode`, nên khi nộp chỉ cần sao chép lớp `Solution`; file [list-node.h](list-node.h) dùng cho việc biên dịch trên máy.
