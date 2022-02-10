public interface Subject {
//  Đăng ký vào danh sách Observers
  public void attach(Observer o);

//  Hủy đăng ký
  public void detach(Observer o);

//  Thông báo đến các Observers
  public void notifyUpdate(Message m);
}
