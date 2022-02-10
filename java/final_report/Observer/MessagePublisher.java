// import java.util.ArrayList;
// import java.util.List;
//
// public class MessagePublisher implements Subject {
//
//  private List<Observer> observers = new ArrayList<>();
//
//  @Override
//  public void attach(Observer o) {
//    observers.add(o);
//  }
//
//  @Override
//  public void detach(Observer o) {
//    observers.remove(o);
//  }
//
//  @Override
//  public void notifyUpdate(Message m) {
//    for (Observer o : observers) {
//      o.update(m);
//    }
//  }
// }
//
//// Observer.java
// public interface Observer {
//  // Khi nhận thông báo từ Subject thì nó thực hiện update
//  public void update(Message m);
// }
//
//
// MessageSubscriberOne.java
// public class MessageSubscriberOne implements Observer {
//  @Override
//  public void update(Message m) {
//    System.out.println("MessageSubscriberOne :: " + m.getMessageContent());
//  }
// }
// MessageSubscriberTwo.java
// public class MessageSubscriberTwo implements Observer {
//  @Override
//  public void update(Message m) {
//    System.out.println("MessageSubscriberTwo :: " + m.getMessageContent());
//  }
// }
// MessageSubscriberThree.java
// public class MessageSubscriberThree implements Observer {
//  @Override
//  public void update(Message m) {
//    System.out.println("MessageSubscriberThree :: " + m.getMessageContent());
//  }
// }

// Message.java
// public class Message {
////  Dùng kiểu final để đảm bảo dữ liệu không bị chỉnh sửa
//  final String messageContent;
//
//  public Message(String m) {
//    this.messageContent = m;
//  }
//
//  public String getMessageContent() {
//    return messageContent;
//  }
// }

//// Main.java
//public class Main {
//  public static void main(String[] args) {
//    MessageSubscriberOne s1 = new MessageSubscriberOne();
//    MessageSubscriberTwo s2 = new MessageSubscriberTwo();
//    MessageSubscriberThree s3 = new MessageSubscriberThree();
//
//    MessagePublisher p = new MessagePublisher();
//
//    p.attach(s1);
//    p.attach(s2);
//
//    p.notifyUpdate(new Message("First Message")); // s1 và s2 sẽ nhận được cập nhật
//
//    p.detach(s1);
//    p.attach(s3);
//
//    p.notifyUpdate(new Message("Second Message")); // s2 và s3 sẽ nhận được cập nhật
//  }
//}

Console
        MessageSubscriberOne :: First Message
        MessageSubscriberTwo :: First Message

        MessageSubscriberTwo :: Second Message
        MessageSubscriberThree :: Second Message