(defun ver-informe ()
  (interactive)
  (async-shell-command
   (concat "mupdf " (org-latex-export-to-pdf))))

(global-set-key (kbd "C-c i") 'ver-informe)

