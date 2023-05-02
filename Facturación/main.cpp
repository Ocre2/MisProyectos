#include <iostream>
#include <vector>
using namespace std;

// estructura para almacenar información de una venta
struct Venta {
   int id;
   float total;
   vector<float> productos;
};

int main() {
   vector<Venta> ventas;
   int opcion;
   float precio, total_venta;
   Venta venta;
   venta.id = 1;

   do {
      cout << "Seleccione una opción:\n";
      cout << "1. Registrar una venta\n";
      cout << "2. Listar las ventas del día\n";
      cout << "0. Salir\n";
      cin >> opcion;


      switch (opcion) {
          case 0:
              cout << "Saliendo del programa...\n";
              break;
         case 1:
            // inicializar los valores de la nueva venta
            venta.productos.clear();
            total_venta = 0;

            // ingresar los precios de los productos y calcular el total
            cout << "Ingrese el precio de cada producto, 0 para terminar:\n";
            do {
               cin >> precio;
               venta.productos.push_back(precio);
               total_venta += precio;
            } while (precio != 0);

            // guardar el total de la venta y agregar la venta a la lista
            venta.total = total_venta;
            ventas.push_back(venta);

            // actualizar el id para la siguiente venta
            venta.id++;

            cout << "Venta registrada con éxito\n";
            break;
         case 2:
            // mostrar todas las ventas del día y la sumatoria de todas las ventas
            float sumatoria = 0;
            cout << "Listado de ventas del día:\n";
            for (Venta v : ventas) {
               cout << "Venta #" << v.id << " - Total: $" << v.total << endl;
               sumatoria += v.total;
            }
            cout << "Sumatoria de todas las ventas: $" << sumatoria << endl;
            break;
      }
   } while (opcion != 0);

   return 0;
}
