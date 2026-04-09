# `CHANGELOG.md`

```markdown
# Historial de Cambios (Changelog)

Todas las modificaciones notables de este proyecto se registran aquí.

## [1.0.1] - 2026-04-08
### Corregido
- Corregido bug: uso incorrecto de `random.sin(...)`. La función trigonométrica
  pertenece al módulo `math`, no a `random`. Se importó `math` y se reemplazó
  `random.sin` por `math.sin`.
- Actualizado docstring y metadata de versión.
- Pequeña nota de registro: este cambio evita el error
  "module 'random' has no attribute 'sin'".

## [1.1.0] - 2026-04-01
### Añadido
- Se añadió el manejo de interrupción por teclado (KeyboardInterrupt). Ahora, si
  el usuario presiona Ctrl+C, el script finaliza el bucle de adquisición de
  forma segura, guardando y graficando los datos recolectados hasta el momento.

## [1.1.1] - 2026-03-25
### Corregido
- Se arreglaron detalles mal implementados al momento de añadir la mejora C
