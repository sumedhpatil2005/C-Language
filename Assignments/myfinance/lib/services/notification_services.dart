import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:timezone/data/latest.dart' as tz;
import 'package:timezone/timezone.dart' as tz;

class NotificationService {
  static final NotificationService _instance = NotificationService._internal();
  factory NotificationService() => _instance;
  NotificationService._internal();

  final FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin =
      FlutterLocalNotificationsPlugin();

  Future<void> init() async {
    // Initialize timezone database
    tz.initializeTimeZones();

    const AndroidInitializationSettings initializationSettingsAndroid =
        AndroidInitializationSettings('@mipmap/ic_launcher');

    const InitializationSettings initializationSettings =
        InitializationSettings(
      android: initializationSettingsAndroid,
    );

    await flutterLocalNotificationsPlugin.initialize(initializationSettings);
  }

  Future<bool> requestNotificationPermissions() async {
    final bool? result = await flutterLocalNotificationsPlugin
        .resolvePlatformSpecificImplementation<
            AndroidFlutterLocalNotificationsPlugin>()
        ?.requestPermission();
    return result ?? false;
  }

  Future<void> showNotificationNow({
    required String title,
    required String body,
  }) async {
    const AndroidNotificationDetails androidPlatformChannelSpecifics =
        AndroidNotificationDetails(
      'monthly_reminder_channel', // Channel ID
      'Monthly Reminders', // Channel name
      channelDescription:
          'Channel for monthly reminders', // Channel description
      importance: Importance.high,
      priority: Priority.high,
      showWhen: false,
    );

    const NotificationDetails platformChannelSpecifics =
        NotificationDetails(android: androidPlatformChannelSpecifics);

    await flutterLocalNotificationsPlugin.show(
      0, // Notification ID
      title,
      body,
      platformChannelSpecifics,
      payload: 'Immediate Reminder', // Optional payload
    );
  }

  Future<void> scheduleMonthlyNotification({
    required int id,
    required String title,
    required String body,
    required int dayOfMonth,
  }) async {
    const AndroidNotificationDetails androidPlatformChannelSpecifics =
        AndroidNotificationDetails(
      'monthly_reminder_channel', // Channel ID
      'Monthly Reminders', // Channel name
      channelDescription:
          'Channel for monthly reminders', // Channel description
      importance: Importance.high,
      priority: Priority.high,
      showWhen: false,
    );

    const NotificationDetails platformChannelSpecifics =
        NotificationDetails(android: androidPlatformChannelSpecifics);

    await flutterLocalNotificationsPlugin.zonedSchedule(
      id,
      title,
      body,
      _nextInstanceOfMonth(dayOfMonth),
      platformChannelSpecifics,
      androidScheduleMode: AndroidScheduleMode.exactAllowWhileIdle,
      matchDateTimeComponents: DateTimeComponents.dayOfMonthAndTime,
      payload: 'Monthly Reminder', // Optional payload
    );
  }

  tz.TZDateTime _nextInstanceOfMonth(int dayOfMonth) {
    final tz.TZDateTime now = tz.TZDateTime.now(tz.local);
    tz.TZDateTime scheduledDate =
        tz.TZDateTime(tz.local, now.year, now.month, dayOfMonth, 9, 0);

    if (scheduledDate.isBefore(now)) {
      scheduledDate =
          tz.TZDateTime(tz.local, now.year, now.month + 1, dayOfMonth, 9, 0);
    }

    return scheduledDate;
  }
}

extension on AndroidFlutterLocalNotificationsPlugin? {
  requestPermission() {}
}
