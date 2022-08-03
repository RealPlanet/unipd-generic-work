#include <iostream>
#include "LaserScannerDriver.h"

/*
    Fabio Ruscica
    Data: 02/12/2020
    V. 1
*/

//Funzione per generare vettori randomizzati
void test_scanner_for_memory_leak(LaserScannerDriver& scanner)
{
    std::vector<double> v0(181, 0);
    std::vector<double> v1(181, 1);
    std::vector<double> v2(181, 2);
    for (int i = 0; i < 100; i++)
    {
        scanner.new_scan(v0);
        scanner.new_scan(v1);
        scanner.new_scan(v2);
    }
}

LaserScannerDriver createScannerMove(double _newResolution)
{
    LaserScannerDriver driver(_newResolution);
    return driver;
}

void stampaTuttiZeri(LaserScannerDriver scanner)
{
    std::vector<double> vempty = { 0 };
    for (int i = 0; i < 100; i++)
    {
        scanner.new_scan(vempty);
    }

    while (scanner.has_scan())
    {
        std::cout << scanner << std::endl;
        vempty = scanner.get_scan();
    }
}


int main()
{
    std::vector<double> v0(100, 1);
    std::vector<double> v1(100, 2);
    std::vector<double> v2(181, 3);
    std::vector<double> v3(100, 4);
    std::vector<double> v4(100, 5);
    LaserScannerDriver scannerTest = createScannerMove(1);
    LaserScannerDriver test(createScannerMove(1)); //Test costruttore move
    LaserScannerDriver test2 = createScannerMove(1);
    LaserScannerDriver test3 = createScannerMove(1);
    LaserScannerDriver constructorCopyTest(test3);
    test.new_scan(v3);
    test2 = std::move(test); //Test operatore move
    test2 = test3; //Test operatore copy

    std::vector<double> a1 = { 1,1,1 };
    std::vector<double> a2 = { 2,2,2 };
    std::cout << "[INFO] Inserisco un nuovo vettore in scanner 1" << std::endl;
    scannerTest.new_scan(a1);
    std::cout << "[INFO] Inserisco un nuovo vettore in scanner 1" << std::endl;
    scannerTest.new_scan(a2);

    std::cout << "[INFO] Copio con costruttore di copia scanner 1 in scanner 2" << std::endl;
    LaserScannerDriver scanner = scannerTest;

    std::cout << "[INFO] Stampo tutti i dati di scanner 1 e li cancello" << std::endl;
    std::cout << std::endl;

    while (scannerTest.has_scan())
    {
        std::vector<double> vTMP = scannerTest.get_scan();
        for (unsigned int i = 0; i < vTMP.size(); i++)
        {
            std::cout << vTMP[i] << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "[INFO] Stampo tutti i dati di scanner 2 e li cancello" << std::endl;
    while (scanner.has_scan())
    {
        std::vector<double> vTMP = scanner.get_scan();
        for (unsigned int i = 0; i < vTMP.size(); i++)
        {
            std::cout << vTMP[i] << " ";
        }
    }

    scanner = createScannerMove(1);
    test_scanner_for_memory_leak(scanner);

    scannerTest = scanner; //Operatore copia

    std::cout << std::endl;
    std::cout << "[INFO] Stampo tutti i dati di scannerTest e li cancello" << std::endl;
    while (scannerTest.has_scan())
    {
        std::vector<double> vTMP = scannerTest.get_scan();
        for (unsigned int i = 0; i < vTMP.size(); i++)
        {
            std::cout << vTMP[i] << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "[INFO] Stampo tutti i dati di scanner e li cancello" << std::endl;
    while (scanner.has_scan())
    {
        std::vector<double> vTMP = scanner.get_scan();
        for (unsigned int i = 0; i < vTMP.size(); i++)
        {
            std::cout << vTMP[i] << " ";
        }
    }

    std::cout  << std::endl;
    std::cout << "[INFO] Testo operatore << nel caso limite di risoluzione 0.1" << std::endl;
    scanner = createScannerMove(0.1); //Inizializzando SOLO zeri senza valore c'era  un problema con i ptr, non tutti venivano inizializati completamente
    stampaTuttiZeri(scanner);         //questo step è solo una verifica di quello
    std::cout << std::endl;
    std::cout << "[INFO] Testo get_distance singolarmente" << std::endl;
    scanner.new_scan(v2);
    std::cout << "V2 contiene ad indice 0: " << v2[0] << " get_distance ad angolo 0 contiene: " << scanner.get_distance(0) << std::endl;

    try
    {
        for (int i = 0; i < 100; i++)  std::vector<double> vTMP = scanner.get_scan();
    }
    catch (LaserScannerDriver::ScanBufferIsEmpty e)
    {
        std::cout << "[INFO] Eccezione ScanBufferIsEmpty lanciata con successo " << std::endl;
    }
    std::cout << std::endl;

    try
    {
        LaserScannerDriver testAngleResolution(1000);
    }
    catch (LaserScannerDriver::InvalidAngleResolution e)
    {
        std::cout << "[INFO] Eccezione InvalidAngleResolution lanciata con successo " << std::endl;
    }
    std::cout << std::endl;

    scanner.new_scan(v2);
    try
    {
        scanner.get_distance(10000);
    }
    catch (LaserScannerDriver::InvalidAngleRequested e)
    {
        std::cout << "[INFO] Eccezione InvalidAngleRequested lanciata con successo " << std::endl;
    }
    std::cout << std::endl;

    scanner.new_scan(v2);
    scanner.new_scan(v2);
    scanner.new_scan(v2);
    scanner.new_scan(v2);
    scanner.new_scan(v2);
    scanner.new_scan(v2);

    scanner.clear_buffer();
    scanner = createScannerMove(0.523456487);

    std::vector<double> v7(2000, 7);
    scanner.new_scan(v7);
    scanner.new_scan(v7);

    std::cout << std::endl;
    std::cout << "[INFO] Test get_distance con angolo 0 e angolo 180" << std::endl;
    std::cout << scanner.get_distance(0) << std::endl;
    std::cout << scanner.get_distance(180) << std::endl;

    std::vector<double> v5(181, 5);
    std::vector<double> v6(181, 6);
    std::vector<double> v8(181, 8);

    scanner.clear_buffer();
    scanner.new_scan(v5);
    scanner.new_scan(v6);
    scanner.new_scan(v8);
    std::cout << std::endl;
    std::cout << "v5 - oldest scan inserted" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << v5[i] << "  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "[INFO] Test get_scan dopo aver inserito in ordine v5, v6, v7 (Stampo solo i primi 10 elementi per controllare)" << std::endl;

    std::vector<double> vectorOUT = scanner.get_scan();
    for (int i = 0; i < 10; i++)
    {
        std::cout << vectorOUT[i] << "  ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "[INFO] Test completato con successo" << std::endl;

    return 0;
}