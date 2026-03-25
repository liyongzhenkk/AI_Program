#include<iostream>
// 写一个 socket 编程示例

// 1. 创建一个 socket
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return -1;
    }
}

// 2. 绑定一个端口
int bind_socket(int sock, int port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    return bind(sock, (struct sockaddr*)&addr, sizeof(addr));
}

// 3. 监听端口
int listen_socket(int sock) {
    return listen(sock, 10);
}

// 4. 接受连接
int accept_socket(int sock) {
    return accept(sock, (struct sockaddr*)&addr, sizeof(addr));
}

// 5. 发送数据
int send_data(int sock, const char* data) {
    return send(sock, data, strlen(data), 0);
}

// 接收数据
int receive_data(int sock, char* data) {
    return recv(sock, data, sizeof(data), 0);
}

// 6. 关闭 socket
int close_socket(int sock) {
    return close(sock);
}


//冒泡排序
    //maopaopaixu  从小到大
    void bubble_sort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

//快速排序
void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}

void test() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    test();
    return 0;
}