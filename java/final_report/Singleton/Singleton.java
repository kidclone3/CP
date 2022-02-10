public final class Singleton {

  // Biến uniqueInstance là biến static, là instance duy nhất của class Singleton.
  private static Singleton uniqueInstance;
  public String value;

  private Singleton(String value) {
    // Contructor Singleton() được khai báo là private
    // để hạn chế khả năng truy cập của các class bên ngoài.
    // Chỉ Singleton mới có thể khởi tạo lớp này.

    // Đoạn code dưới đây sẽ bắt thread phải chờ 1s trước khi gán giá trị.
    try {
      Thread.sleep(1000);
    } catch (InterruptedException ex) {
      ex.printStackTrace();
    }
    this.value = value;
  }

  public static Singleton getInstance(String value) {
    // Nếu instance đang là null thì khởi tạo,
    // ngược lại sẽ trả về nó.
    if (uniqueInstance == null) {
      uniqueInstance = new Singleton(value);
    }
    return uniqueInstance;
  }
}
