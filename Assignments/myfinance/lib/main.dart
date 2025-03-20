import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:myfinance/presentations/views/login_screen.dart';
import 'package:myfinance/presentations/views/signup_screen.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/views/homescreen.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';
import 'package:myfinance/services/notification_services.dart';
//import 'package:myfinance/presentations/views/login_screen.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(
      options: const FirebaseOptions(
          apiKey: "AIzaSyDsTmY4Tf3SGrF2oHrf0NGLXvpVwFVepKk",
          appId: "1:660481665768:android:97025d2b206aa6be2df75d",
          messagingSenderId: "660481665768",
          projectId: "myfinance-2f4a3")); // Initialize Firebase
  await NotificationService().init(); // Initialize notifications
  runApp(
    MultiProvider(
      providers: [
        ChangeNotifierProvider(create: (_) => TransactionProvider()),
      ],
      child: const MyApp(),
    ),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Expense Management',
      theme: ThemeData(
          appBarTheme: AppBarTheme(color: Colors.white),
          iconTheme: IconThemeData(color: Colors.white)),
      initialRoute: '/login', // Set initial route to '/login'
      routes: {
        '/home': (context) => const HomeScreen(),
        '/login': (context) => const LoginScreen(),
        '/signup': (context) => const SignupScreen(),
      },
    );
  }
}
