==362311== Memcheck, a memory error detector
==362311== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==362311== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==362311== Command: ./Arcatek -g /home/hugo/Epitech/epi_arcade/Bin/pacman.so -d /home/hugo/Epitech/epi_arcade/Bin/sdl2.so
==362311== 
1 game DLLs loaded.
1 display DLLs loaded.
Loading game library: /home/hugo/Epitech/epi_arcade/Bin/pacman.so
==362311== Conditional jump or move depends on uninitialised value(s)
==362311==    at 0x1108C8: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count(std::__shared_count<(__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1077)
==362311==    by 0x10FBFA: std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2>::__shared_ptr(std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1522)
==362311==    by 0x10FC24: std::shared_ptr<ArcaTek::Game::IGame>::shared_ptr(std::shared_ptr<ArcaTek::Game::IGame> const&) (shared_ptr.h:204)
==362311==    by 0x10FC67: decltype (::new ((void*)(0)) std::shared_ptr<ArcaTek::Game::IGame>((declval<std::shared_ptr<ArcaTek::Game::IGame> const&>)())) std::construct_at<std::shared_ptr<ArcaTek::Game::IGame>, std::shared_ptr<ArcaTek::Game::IGame> const&>(std::shared_ptr<ArcaTek::Game::IGame>*, std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_construct.h:97)
==362311==    by 0x10EB57: construct<std::shared_ptr<ArcaTek::Game::IGame>, const std::shared_ptr<ArcaTek::Game::IGame>&> (alloc_traits.h:540)
==362311==    by 0x10EB57: void std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::_M_realloc_insert<std::shared_ptr<ArcaTek::Game::IGame> const&>(__gnu_cxx::__normal_iterator<std::shared_ptr<ArcaTek::Game::IGame>*, std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > > >, std::shared_ptr<ArcaTek::Game::IGame> const&) (vector.tcc:468)
==362311==    by 0x10D831: std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::push_back(std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_vector.h:1292)
==362311==    by 0x10B999: ArcaTek::Core::Core(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >) (Core.cpp:20)
==362311==    by 0x112C2E: main (main.cpp:20)
==362311== 
==362311== Use of uninitialised value of size 8
==362311==    at 0x111289: __atomic_add_single (atomicity.h:92)
==362311==    by 0x111289: __atomic_add_dispatch (atomicity.h:109)
==362311==    by 0x111289: std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_add_ref_copy() (shared_ptr_base.h:152)
==362311==    by 0x1108D8: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count(std::__shared_count<(__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1078)
==362311==    by 0x10FBFA: std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2>::__shared_ptr(std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1522)
==362311==    by 0x10FC24: std::shared_ptr<ArcaTek::Game::IGame>::shared_ptr(std::shared_ptr<ArcaTek::Game::IGame> const&) (shared_ptr.h:204)
==362311==    by 0x10FC67: decltype (::new ((void*)(0)) std::shared_ptr<ArcaTek::Game::IGame>((declval<std::shared_ptr<ArcaTek::Game::IGame> const&>)())) std::construct_at<std::shared_ptr<ArcaTek::Game::IGame>, std::shared_ptr<ArcaTek::Game::IGame> const&>(std::shared_ptr<ArcaTek::Game::IGame>*, std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_construct.h:97)
==362311==    by 0x10EB57: construct<std::shared_ptr<ArcaTek::Game::IGame>, const std::shared_ptr<ArcaTek::Game::IGame>&> (alloc_traits.h:540)
==362311==    by 0x10EB57: void std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::_M_realloc_insert<std::shared_ptr<ArcaTek::Game::IGame> const&>(__gnu_cxx::__normal_iterator<std::shared_ptr<ArcaTek::Game::IGame>*, std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > > >, std::shared_ptr<ArcaTek::Game::IGame> const&) (vector.tcc:468)
==362311==    by 0x10D831: std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::push_back(std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_vector.h:1292)
==362311==    by 0x10B999: ArcaTek::Core::Core(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >) (Core.cpp:20)
==362311==    by 0x112C2E: main (main.cpp:20)
==362311== 
==362311== Use of uninitialised value of size 8
==362311==    at 0x111294: __atomic_add_single (atomicity.h:92)
==362311==    by 0x111294: __atomic_add_dispatch (atomicity.h:109)
==362311==    by 0x111294: std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_add_ref_copy() (shared_ptr_base.h:152)
==362311==    by 0x1108D8: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count(std::__shared_count<(__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1078)
==362311==    by 0x10FBFA: std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2>::__shared_ptr(std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1522)
==362311==    by 0x10FC24: std::shared_ptr<ArcaTek::Game::IGame>::shared_ptr(std::shared_ptr<ArcaTek::Game::IGame> const&) (shared_ptr.h:204)
==362311==    by 0x10FC67: decltype (::new ((void*)(0)) std::shared_ptr<ArcaTek::Game::IGame>((declval<std::shared_ptr<ArcaTek::Game::IGame> const&>)())) std::construct_at<std::shared_ptr<ArcaTek::Game::IGame>, std::shared_ptr<ArcaTek::Game::IGame> const&>(std::shared_ptr<ArcaTek::Game::IGame>*, std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_construct.h:97)
==362311==    by 0x10EB57: construct<std::shared_ptr<ArcaTek::Game::IGame>, const std::shared_ptr<ArcaTek::Game::IGame>&> (alloc_traits.h:540)
==362311==    by 0x10EB57: void std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::_M_realloc_insert<std::shared_ptr<ArcaTek::Game::IGame> const&>(__gnu_cxx::__normal_iterator<std::shared_ptr<ArcaTek::Game::IGame>*, std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > > >, std::shared_ptr<ArcaTek::Game::IGame> const&) (vector.tcc:468)
==362311==    by 0x10D831: std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::push_back(std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_vector.h:1292)
==362311==    by 0x10B999: ArcaTek::Core::Core(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >) (Core.cpp:20)
==362311==    by 0x112C2E: main (main.cpp:20)
==362311== 
==362311== 
==362311== Process terminating with default action of signal 11 (SIGSEGV)
==362311==  Bad permissions for mapped region at address 0x1134B7
==362311==    at 0x111294: __atomic_add_single (atomicity.h:92)
==362311==    by 0x111294: __atomic_add_dispatch (atomicity.h:109)
==362311==    by 0x111294: std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_add_ref_copy() (shared_ptr_base.h:152)
==362311==    by 0x1108D8: std::__shared_count<(__gnu_cxx::_Lock_policy)2>::__shared_count(std::__shared_count<(__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1078)
==362311==    by 0x10FBFA: std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2>::__shared_ptr(std::__shared_ptr<ArcaTek::Game::IGame, (__gnu_cxx::_Lock_policy)2> const&) (shared_ptr_base.h:1522)
==362311==    by 0x10FC24: std::shared_ptr<ArcaTek::Game::IGame>::shared_ptr(std::shared_ptr<ArcaTek::Game::IGame> const&) (shared_ptr.h:204)
==362311==    by 0x10FC67: decltype (::new ((void*)(0)) std::shared_ptr<ArcaTek::Game::IGame>((declval<std::shared_ptr<ArcaTek::Game::IGame> const&>)())) std::construct_at<std::shared_ptr<ArcaTek::Game::IGame>, std::shared_ptr<ArcaTek::Game::IGame> const&>(std::shared_ptr<ArcaTek::Game::IGame>*, std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_construct.h:97)
==362311==    by 0x10EB57: construct<std::shared_ptr<ArcaTek::Game::IGame>, const std::shared_ptr<ArcaTek::Game::IGame>&> (alloc_traits.h:540)
==362311==    by 0x10EB57: void std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::_M_realloc_insert<std::shared_ptr<ArcaTek::Game::IGame> const&>(__gnu_cxx::__normal_iterator<std::shared_ptr<ArcaTek::Game::IGame>*, std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > > >, std::shared_ptr<ArcaTek::Game::IGame> const&) (vector.tcc:468)
==362311==    by 0x10D831: std::vector<std::shared_ptr<ArcaTek::Game::IGame>, std::allocator<std::shared_ptr<ArcaTek::Game::IGame> > >::push_back(std::shared_ptr<ArcaTek::Game::IGame> const&) (stl_vector.h:1292)
==362311==    by 0x10B999: ArcaTek::Core::Core(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >) (Core.cpp:20)
==362311==    by 0x112C2E: main (main.cpp:20)
==362311== 
==362311== HEAP SUMMARY:
==362311==     in use at exit: 82,454 bytes in 24 blocks
==362311==   total heap usage: 32 allocs, 8 frees, 82,764 bytes allocated
==362311== 
==362311== LEAK SUMMARY:
==362311==    definitely lost: 16 bytes in 1 blocks
==362311==    indirectly lost: 0 bytes in 0 blocks
==362311==      possibly lost: 2,304 bytes in 1 blocks
==362311==    still reachable: 80,134 bytes in 22 blocks
==362311==         suppressed: 0 bytes in 0 blocks
==362311== Rerun with --leak-check=full to see details of leaked memory
==362311== 
==362311== Use --track-origins=yes to see where uninitialised values come from
==362311== For lists of detected and suppressed errors, rerun with: -s
==362311== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
