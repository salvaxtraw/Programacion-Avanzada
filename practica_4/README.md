# Registro de Sensores - Proyecto de Adquisición (Mejora C)

Este repositorio contiene una herramienta en Python diseñada para la adquisición, procesamiento y análisis de datos de sensores (Temperatura y LDR). El proyecto está orientado a entornos de ingeniería, permitiendo la transición de lecturas crudas a información procesada mediante detección de eventos.

## 🛠️ Características
- **Adquisición Dual:** Soporte para simulación de señales con ruido gaussiano y deriva térmica.
- **Detección de Eventos (Mejora C):** Identificación automática de picos de luz (LDR) superiores a un umbral definido.
- **Persistencia Robusta:** Escritura atómica de archivos para prevenir corrupción de datos.
- **Visualización:** Generación automática de gráficas con anotaciones de eventos.

## 🚀 Instalación y Uso

### Requisitos previos
- Python 3.8 o superior.
- Entorno virtual (recomendado).

```bash
# Crear y activar entorno virtual
python -m venv venv
source venv/bin/activate  # En Windows: venv\Scripts\activate

# Instalar dependencias
pip install matplotlib numpy

# Para este despliegue, utilizamos el modo simulación para validar la detección de picos:
python src/run_acquisition.py --mode sim --duration 60 --interval 1
