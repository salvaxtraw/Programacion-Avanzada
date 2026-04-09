# `Análisis Técnico - Mejora C (Detección de Eventos)`

## Introducción
La capacidad de transformar datos en eventos es fundamental en el monitoreo industrial. En esta etapa, el sistema dejó de ser un simple registrador pasivo para convertirse en un monitor inteligente de picos de luminosidad.

## Metodología de Detección
Se implementó un umbral estático ($Threshold = 800$) sobre la lectura del ADC del LDR. 
1. **Filtro de Condición:** Si $LDR_{raw} \geq 800$, el sistema etiqueta la muestra como `PICO_LUZ_DETECTADO`.
2. **Registro:** El evento se vincula al *timestamp* exacto de la muestra.

## Comparativa Antes/Después
| Característica | Versión Base (v1.0.1) | Versión Mejorada (v1.1.0) |
| :--- | :--- | :--- |
| **Análisis de Datos** | Manual (Post-procesamiento) | Automático (Tiempo real) |
| **Visualización** | Líneas continuas simples | Líneas con marcadores de alerta |
| **Salida de Datos** | 1 Archivo (CSV) | 2 Archivos (CSV + Event Log) |

## Conclusión
La implementación de la Mejora C permite reducir el tiempo de respuesta ante anomalías. En un escenario real (no simulado), esto podría activar alarmas o disparar protocolos de seguridad automáticamente.
