function [chi_d] = guidance(x_t, y_t, x_ref, y_ref, x, y)
pi_p = atan2(y_t - y_ref, x_t - x_ref);
delta = 800; %look ahead distance
Kp = 1 / delta;
y_e = crosstrackWpt(x_t, y_t, x_ref, y_ref, x, y);
chi_d = pi_p - atan(Kp * y_e);
%chi_d = wrapTo2Pi(chi_d);
end